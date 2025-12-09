#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <ranges>
#include <iostream>

struct CracklePopData {
    uint input;
    std::string output;
};

auto cracklePop() -> void {
    std::ranges::for_each(std::views::iota(1u, 101u), [](uint i) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "CracklePop ";
        } else if (i % 3 == 0) {
            std::cout << "Crackle ";
        } else if (i % 5 == 0) {
            std::cout << "Pop ";
        } else {
            std::cout << i << " ";
        }
    });
}

int main() {
    cracklePop();
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
