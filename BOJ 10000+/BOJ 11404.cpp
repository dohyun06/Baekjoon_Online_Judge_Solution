#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000000

int n, m;
std::vector<std::vector<int>> dist;

void floyd() {
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++)
      for (int k = 1; k < n + 1; k++)
        dist[j][k] = std::min(dist[j][k], dist[j][i] + dist[i][k]);
}


int main(void) {
  std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

  int a, b, c;

  std::cin >> n >> m;

  dist.resize(n + 1, std::vector<int>(n + 1, INF));
  for (int i = 1; i < n + 1; i++) dist[i][i] = 0;

  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    dist[a][b] = std::min(dist[a][b], c);
  }

  floyd();

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++)
      std::cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
    std::cout << '\n';
  }

  return 0;
}