#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int N, size = 2, fish, sum, ax[4] = { -1,1,0,0 }, ay[4] = { 0,0,-1,1 };
std::vector<std::vector<int>> graph;
std::vector<std::vector<bool>> check;
std::priority_queue<std::tuple<int, int, int>> pq;

void bfs() {
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		int d = -std::get<0>(t), x = -std::get<1>(t), y = -std::get<2>(t);

		if (0 < graph[x][y] && graph[x][y] < size) {
			fish++;
			if (fish == size) {
				size++;
				fish = 0;
			}
			graph[x][y] = 0;
			sum += d;
			d = 0;
			std::fill(check.begin(), check.end(), std::vector<bool>(N, false));

			while (!pq.empty()) pq.pop();
		}
		for (int i = 0; i < 4; i++) {
			int bx = x + ax[i], by = y + ay[i];

			if (bx < 0 || by < 0 || bx >= N || by >= N) continue;
			if (check[bx][by]) continue;
			if (0 < graph[bx][by] && graph[bx][by] > size) continue;
			
			pq.push(std::make_tuple(-d - 1, -bx, -by));
			check[bx][by] = true;
		}
	}
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	std::cin >> N;

	graph.resize(N, std::vector<int>(N));
	check.resize(N, std::vector<bool>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> graph[i][j];
			if (graph[i][j] == 9) {
				pq.push({ 0,-i,-j });
				graph[i][j] = 0;
			}
		}
	}
	bfs();

	std::cout << sum;

	return 0;
}