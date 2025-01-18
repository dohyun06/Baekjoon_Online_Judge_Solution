#include <iostream>
#include <queue>
#include <vector>

int                            n, m;
int                            person = 0;
std::vector<std::vector<bool>> check;
std::vector<std::vector<int>>  map, res;

void bfs(std::pair<int, int> now) {
  std::queue<std::pair<int, int>> q;

  check[now.second][now.first] = true;
  q.push(now);

  while (!q.empty()) {
    now = q.front();

    q.pop();

    if (map[now.second][now.first] != 0) {
      if (now.first > 0 && !check[now.second][now.first - 1]) {
        q.push({now.first - 1, now.second});
        check[now.second][now.first - 1] = true;
        res[now.second][now.first - 1]   = res[now.second][now.first] + 1;
      }
      if (now.first < m - 1 && !check[now.second][now.first + 1]) {
        q.push({now.first + 1, now.second});
        check[now.second][now.first + 1] = true;
        res[now.second][now.first + 1]   = res[now.second][now.first] + 1;
      }
      if (now.second > 0 && !check[now.second - 1][now.first]) {
        q.push({now.first, now.second - 1});
        check[now.second - 1][now.first] = true;
        res[now.second - 1][now.first]   = res[now.second][now.first] + 1;
      }
      if (now.second < n - 1 && !check[now.second + 1][now.first]) {
        q.push({now.first, now.second + 1});
        check[now.second + 1][now.first] = true;
        res[now.second + 1][now.first]   = res[now.second][now.first] + 1;
      }
    }
  }
}

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int x, y;

  std::cin >> n >> m;

  map.resize(n, std::vector<int>(m));
  res.resize(n, std::vector<int>(m, -1));
  check.resize(n, std::vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> map[i][j];
      if (map[i][j] == 2) {
        x         = j;
        y         = i;
        res[i][j] = 0;
      }
      else if (!map[i][j]) {
        res[i][j]   = 0;
        check[i][j] = true;
      }
    }
  };

  bfs({x, y});

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) std::cout << res[i][j] << ' ';
    std::cout << '\n';
  }

  return 0;
}