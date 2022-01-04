#include <iostream>
#include <vector>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N;

	std::cin >> N;

	std::vector<std::vector<int>> graph(N, std::vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> graph[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (graph[j][i] && graph[i][k]) {
					graph[j][k] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << graph[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}