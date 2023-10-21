#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> dis;
std::vector<bool> check;
std::vector<std::vector<std::pair<int, int>>> graph;

void dfs(int now) {
  check[now] = true;

  for (int i = 0; i < graph[now].size(); i++) {
    if (!check[graph[now][i].first]) {
      dis[graph[now][i].first] = dis[now] + graph[now][i].second;

      dfs(graph[now][i].first);
    }
  }
}

int main(void) {
  std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

  int n, input1, input2, input3, temp = 0, start;

  std::cin >> n;

  if (n == 1) {
    std::cout << 0;
    return 0;
  }

  graph.resize(n + 1);
  check.resize(n + 1);
  dis.resize(n + 1);

  for (int i = 0; i < n - 1; i++) {
    std::cin >> input1 >> input2 >> input3;
    
    graph[input1].push_back({ input2, input3 });
    graph[input2].push_back({ input1, input3 });
  }

  dfs(1);

  for (int i = 1; i < dis.size(); i++) {
    if (temp < dis[i]) {
      start = i;
      temp = dis[i];
    }
  }

  check = std::vector<bool>(n + 1, false);
  dis = std::vector<int>(n + 1, 0);

  dfs(start);

  std::sort(dis.begin(), dis.end());

  std::cout << dis[dis.size() - 1];

  return 0;
}