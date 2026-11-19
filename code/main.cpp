#include <algorithm>
#include <fstream>
#include <random>
#include <vector>

int main() {
  std::vector<int> integers;
  integers.resize(20);

  // output
  std::ofstream output("data/output.txt");

  auto out_lambda = [&output](const std::vector<int>& array) {
    // output << integers << "\n";

    output << "\n";
  };

  // 1 - Generate
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(-50, 100);

  std::generate(integers.begin(), integers.end(),
                [dist, gen]() { return dist(gen); });
  out_lambda(integers);

  // 2 - min/max
  int min, max;
  min = *std::min_element(integers.begin(), integers.end());
  max = *std::max_element(integers.begin(), integers.end());
  out_lambda(integers);

  // 3 -

  // 4 -

  // 5 -

  output.close();

  return 0;
}