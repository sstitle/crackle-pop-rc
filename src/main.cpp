// This code is hosted on GitHub at:
// https://github.com/sstitle/crackle-pop-rc

#include <array>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>

struct Rule {
  uint divisor;
  std::string_view text;
};

constexpr std::array<Rule, 2> rules = {{{3, "Crackle"}, {5, "Pop"}}};

auto cracklePopPipeline(uint i) -> std::string {
  auto result = std::accumulate(
      rules.begin(), rules.end(), std::string{},
      [i](const std::string& acc, const Rule& rule) -> std::string {
        return acc + (i % rule.divisor == 0 ? std::string(rule.text) : "");
      });

  return result.empty() ? std::to_string(i) : result;
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
