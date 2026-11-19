#include <fstream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> integers;

  // output
  std::ofstream output("data/output.txt");

  auto out_lambda = [&output](const std::vector<int>& array) {
    for (const int& item : array) {
      output << item << "\n";
    }
    output << "\n";
  };

  // 1 - Generate
  std::generate(integers.begin(), integers.end(), []() { return 10; });


  // 2 - 
  

  // 3 - 
  

  // 4 -
  

  // 5 - 
  

  output.close();

  return 0;
}