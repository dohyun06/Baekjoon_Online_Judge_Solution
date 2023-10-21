#include <iostream>
#include <vector>
#include <queue>

#define INF 200001

int V, E, K;
std::vector<long long> dist;
std::vector<std::vector<std::pair<int, int>>> path;

void dijkstra(){
	std::priority_queue<std::pair<long long, long long>> pq;

	pq.push(std::make_pair(0, K));
	dist[K] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < path[cur].size(); i++){
			int next = path[cur][i].first, nextCost = cost + path[cur][i].second;
			
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(std::make_pair(-nextCost, next));
			}
		}
	}
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

  std::cin >> V >> E >> K;

	path.resize(V + 1);
	dist.resize(V + 1, INF);

  int u, v, w;

	for (int i = 0; i < E; i++) {
		std::cin >> u >> v >> w;
		path[u].push_back({ v, w });
	}

	dijkstra();

  for (int i = 0; i < dist.size(); i++)
    if (dist[i] < 1000000) std::cout << dist[i] << '\n';
    else std::cout << "INF" << '\n';

	return 0;
}