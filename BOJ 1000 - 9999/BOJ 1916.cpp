#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999

int N, M, begin, end;
std::vector<int> dist;
std::vector<std::vector<std::pair<int, int>>> bus;

void dijkstra(){
	std::priority_queue<std::pair<int, int>> pq;

	pq.push(std::make_pair(0, begin));
	dist[begin] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i=0;i<bus[cur].size();i++){
			int next = bus[cur][i].first, nextCost = cost + bus[cur][i].second;
			
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(std::make_pair(-nextCost, next));
			}
		}
	}
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int from, to, cost;

	std::cin >> N >> M;

	bus.resize(N + 1);
	dist.resize(N + 1, INF);

	for (int i = 0; i < M; i++) {
		std::cin >> from >> to >> cost;
		bus[from].push_back({ to, cost });
	}
	std::cin >> begin >> end;

	dijkstra();

	std::cout << dist[end];

	return 0;
}