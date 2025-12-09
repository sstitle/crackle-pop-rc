#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sys/types.h>

struct CracklePopData {
    uint input;
    std::string output;
};

auto cracklePop() -> void {
    for (uint i = 1; i < 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "CracklePop ";
        } else if (i % 3 == 0) {
            std::cout << "Crackle ";
        } else if (i % 5 == 0) {
            std::cout << "Pop ";
        } else {
            std::cout << i << " ";
        }
    }
}

int main() {
    cracklePop();
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
