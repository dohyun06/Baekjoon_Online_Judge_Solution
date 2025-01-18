#include <cmath>
#include <iostream>
#include <vector>

int                              N, M, res = 2147483647;
std::vector<std::pair<int, int>> chicken, house, combi;

void findCombi(int index, int now) {
  if (index == M) {
    int tmpRes = 0;
    for (auto house : house) {
      int min = 2147483647;
      for (auto combi : combi)
        min = std::min(std::abs(house.first - combi.first) + std::abs(house.second - combi.second), min);
      tmpRes += min;
    }
    res = std::min(tmpRes, res);

    return;
  }
  for (int i = now; i < chicken.size(); i++) {
    combi[index] = chicken[i];
    findCombi(index + 1, i + 1);
  }
  return;
}

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int input;

  std::cin >> N >> M;
  combi.resize(M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> input;
      if (input == 2) chicken.push_back({j, i});
      if (input == 1) house.push_back({j, i});
    }
  }

  findCombi(0, 0);

  std::cout << res;

  return 0;
}