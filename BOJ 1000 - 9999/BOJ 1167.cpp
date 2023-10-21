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

  int V, node, input1, input2, temp = 0, start;

  std::cin >> V;

  graph.resize(V + 1);
  check.resize(V + 1);
  dis.resize(V + 1);

  for (int i = 0; i < V; i++) {
    std::cin >> node;

    while (true) {
      std::cin >> input1;
      if (input1 == -1) break;
      std::cin >> input2;
      
      graph[node].push_back({input1, input2});
      graph[input1].push_back({node, input2});
    }
  }

  dfs(1);

  for (int i = 1; i < dis.size(); i++) {
    if (temp < dis[i]) {
      start = i;
      temp = dis[i];
    }
  }

  check = std::vector<bool>(V + 1, false);
  dis = std::vector<int>(V + 1, 0);

  dfs(start);

  std::sort(dis.begin(), dis.end());

  std::cout << dis[dis.size() - 1];

  return 0;
}