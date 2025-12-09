// This code is hosted on GitHub at:
// https://github.com/sstitle/crackle-pop-rc

#include <cstdlib>
#include <expected>
#include <iostream>
#include <ranges>
#include <string>

// expected<int, string>:
//   - holds int (number) while unprocessed
//   - holds string (result) once matched
using CracklePopState = std::expected<uint, std::string>;

constexpr auto handle(uint divisor, std::string_view text) {
  return [=](uint number) -> CracklePopState {
    if (number % divisor == 0) {
      return std::unexpected(std::string(text));
    }
    return number;
  };
}

constexpr auto finish(CracklePopState state) -> std::string {
  if (state.has_value()) {
    return std::to_string(state.value());
  }
  return state.error();
}

constexpr auto cracklePopPipeline(uint i) -> std::string {
  return finish(CracklePopState{i}
                    .and_then(handle(15, "CracklePop"))
                    .and_then(handle(3, "Crackle"))
                    .and_then(handle(5, "Pop")));
}

constexpr uint MAX_VALUE = 100;

auto cracklePop() -> void {
  for (auto i : std::views::iota(1U, MAX_VALUE + 1)) {
    std::cout << cracklePopPipeline(i) << '\n';
  }
}

int main() {
  cracklePop();
  return EXIT_SUCCESS;
}
