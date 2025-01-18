#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int n, X;
  std::cin >> n >> X;

  std::vector<int> price(n);
  for (int i = 0; i < n; i++) std::cin >> price[i];

  std::sort(price.begin(), price.end());

  for (int i = 0; i < n - 1; i++) {
    if (price[i] + price[i + 1] > X) {
      std::cout << i + 1;
      return 0;
    }
  }

  std::cout << n;

  return 0;
}