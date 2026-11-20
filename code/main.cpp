#include <algorithm>
#include <fstream>
#include <numeric>
#include <random>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> integers;
  integers.resize(20);

  // output
  std::ofstream output("data/output.txt");

  auto out_lambda = [&output](const std::vector<int>& array) {
    std::copy(array.begin(), array.end(),
              std::ostream_iterator<int>(output, " "));

    output << "\n";
  };

  // 1 - Generate
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(-50, 100);

  std::generate(integers.begin(), integers.end(),
                [&dist, &gen]() { return dist(gen); });
  out_lambda(integers);

  // 2 - min/max
  int min, max;
  min = *std::min_element(integers.begin(), integers.end());
  max = *std::max_element(integers.begin(), integers.end());
  output << "Min: " << min << " \nMax: " << max << "\n";

  // 3 - sort
  std::sort(integers.begin(), integers.end());
  out_lambda(integers);

  // 4 - count
  int pos, neg, nul;
  pos = std::count_if(integers.begin(), integers.end(),
                      [](int a) { return a > 0; });
  nul = std::count_if(integers.begin(), integers.end(),
                      [](int a) { return a == 0; });
  neg = std::count_if(integers.begin(), integers.end(),
                      [](int a) { return a < 0; });

  output << "Pos: " << pos << " \nNul: " << nul << " \nNeg: " << neg << "\n";

  // 5 - summ
  int summ;
  summ = std::accumulate(integers.begin(), integers.end(), 0);
  float medium = float(summ) / integers.size();
  output << "Medium: " << medium << "\n";

  // 6 - remove
  std::erase_if(integers, [medium](int a) { return a < medium; });
  out_lambda(integers);

  // 7 - sort and unique
  std::sort(integers.begin(), integers.end());
  std::vector<int> new_ints = integers;
  auto newEnd = std::unique(new_ints.begin(), new_ints.end());
  new_ints.erase(newEnd, new_ints.end());

  out_lambda(new_ints);

  output.close();

  return 0;
}