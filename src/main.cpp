#include <cstdlib>
#include <string>
#include <ranges>
#include <iostream>
#include <expected>

// expected<int, string>:
//   - holds int (number) while unprocessed
//   - holds string (result) once matched
using CracklePopState = std::expected<int, std::string>;

// A generic step to handle divisibility
auto handle(int divisor, std::string_view text) {
    return [=](int number) -> CracklePopState {
        if (number % divisor == 0) {
            return std::unexpected(std::string(text));
        }
        return number;
    };
}

// Terminal: extract final result
auto finish(CracklePopState state) -> std::string {
    if (state.has_value()) {
        return std::to_string(state.value());
    }
    return state.error();
}

// The CracklePop pipeline with std::expected chaining
auto cracklePopPipeline(int i) -> std::string {
    return finish(
        CracklePopState{i}
            .and_then(handle(15, "CracklePop"))
            .and_then(handle(3, "Crackle"))
            .and_then(handle(5, "Pop"))
    );
}

auto cracklePop() -> void {
    auto results = std::views::iota(1, 101)
        | std::views::transform(cracklePopPipeline);

    bool first = true;
    for (const auto& s : results) {
        if (!first) std::cout << ",";
        std::cout << s;
        first = false;
    }
    std::cout << "\n";
}

int main() {
    cracklePop();
    return EXIT_SUCCESS;
}
