#include <iostream>
#include <queue>
#include <vector>

int                           N;
std::vector<std::vector<int>> check, dp;

void bfs(std::pair<int, int> now) {
  std::queue<std::pair<int, int>> q;

  check[now.second][now.first] = 1;
  dp[now.second][now.first]    = 1;
  q.push(now);

  while (!q.empty()) {
    now                          = q.front();
    check[now.second][now.first] = 1;

    q.pop();

    if (now.first + 1 < N && !check[now.second][now.first + 1]) {
      q.push({now.first + 1, now.second});
      dp[now.second][now.first + 1] += dp[now.second][now.first];
    }
    if (now.second + 1 < N && !check[now.second + 1][now.first]) {
      q.push({now.first, now.second + 1});
      dp[now.second + 1][now.first] += dp[now.second][now.first];
    }
    if (now.first + 1 < N && now.second + 1 < N && !check[now.second + 1][now.first + 1])
      dp[now.second + 1][now.first + 1] += dp[now.second][now.first];
  }
}

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  std::cin >> N;

  dp.resize(N, std::vector<int>(N, 0));
  check.resize(N, std::vector<int>(N, 0));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) std::cin >> check[i][j];

  bfs({0, 0});

  std::cout << dp[N - 1][N - 1];

  return 0;
}