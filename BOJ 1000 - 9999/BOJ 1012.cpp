#include <iostream>
#include <vector>

int M, N, sum;
std::vector<std::vector<int>> graph;
std::vector<std::vector<bool>> check;

void dfs(int x, int y) {
    if (graph[y][x] == 1 && check[y][x] == false) {
        check[y][x] = true;

        if (x != 0) dfs(x - 1, y);
        if (x != M-1) dfs(x + 1, y);
        if (y != 0) dfs(x, y - 1);
        if (y != N-1) dfs(x, y + 1);
    }
    else return;
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int T, K;

    std::cin >> T;

    while (T--) {
        std::cin >> M >> N >> K;

        sum = 0;
        graph.resize(N, std::vector<int>(M, 0));
        check.resize(N, std::vector<bool>(M, false));

        for (int i = 0; i < K; i++) {
            int x, y;

            std::cin >> x >> y;

            graph[y][x] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 1 && check[i][j] == false) {
                    dfs(j, i);
                    sum++;
                }
            }
        }

        graph.resize(0);
        check.resize(0);

        std::cout << sum << '\n';
    }

	return 0;
}