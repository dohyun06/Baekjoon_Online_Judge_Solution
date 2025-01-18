#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int              n, input;
  int              res = 0;
  std::vector<int> op;

  std::cin >> n;
  op.resize(n);
  if (!n) {
    std::cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) std::cin >> op[i];

  std::sort(op.begin(), op.end());

  for (int i = std::floor(n * 0.15 + 0.5); i < n - std::floor(n * 0.15 + 0.5); i++) res += op[i];
  std::cout << std::floor(res / (n - 2 * std::floor(n * 0.15 + 0.5)) + 0.5);
  return 0;
}
