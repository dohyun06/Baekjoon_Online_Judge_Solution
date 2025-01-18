#include <iostream>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  float W, H, area;
  std::cin >> W >> H;

  area = W * H / 2;

  std::cout << area;
  if (area == (int)area) std::cout << ".0";

  return 0;
}
