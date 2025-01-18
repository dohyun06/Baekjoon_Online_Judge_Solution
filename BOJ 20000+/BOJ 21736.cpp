#include <iostream>
#include <queue>
#include <vector>

int                            N, M;
int                            person = 0;
std::vector<std::vector<bool>> check;
std::vector<std::string>       campus;

void bfs(std::pair<int, int> now) {
  std::queue<std::pair<int, int>> q;

  check[now.second][now.first] = true;
  q.push(now);

  while (!q.empty()) {
    now = q.front();

    q.pop();

    if (campus[now.second][now.first] == 'P') person++;
    if (campus[now.second][now.first] != 'X') {
      if (now.first > 0 && !check[now.second][now.first - 1]) {
        q.push({now.first - 1, now.second});
        check[now.second][now.first - 1] = true;
      }
      if (now.first < M - 1 && !check[now.second][now.first + 1]) {
        q.push({now.first + 1, now.second});
        check[now.second][now.first + 1] = true;
      }
      if (now.second > 0 && !check[now.second - 1][now.first]) {
        q.push({now.first, now.second - 1});
        check[now.second - 1][now.first] = true;
      }
      if (now.second < N - 1 && !check[now.second + 1][now.first]) {
        q.push({now.first, now.second + 1});
        check[now.second + 1][now.first] = true;
      }
    }
  }
}

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int x, y;

  std::cin >> N >> M;

  campus.resize(N);
  check.resize(N, std::vector<bool>(M, false));

  for (int i = 0; i < N; i++) {
    std::cin >> campus[i];
    for (int j = 0; j < M; j++) {
      if (campus[i][j] == 'I') {
        x = j;
        y = i;
      }
    }
  };

  bfs({x, y});

  if (person)
    std::cout << person;
  else
    std::cout << "TT";

  return 0;
}