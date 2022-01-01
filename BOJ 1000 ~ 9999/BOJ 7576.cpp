#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int M, N;
std::vector<std::vector<int>> graph;
std::queue<std::pair<int, int>> q;

void bfs() {
    std::pair<int, int> now;

    while (!q.empty()) {
        now = q.front();
        q.pop();

        if (now.first != 0 && graph[now.second][now.first - 1] == 0) {
            q.push({ now.first - 1, now.second });
            graph[now.second][now.first - 1] = graph[now.second][now.first]+1;
        }
        if (now.first != M - 1 && graph[now.second][now.first + 1] == false) {
            q.push({ now.first + 1, now.second });
            graph[now.second][now.first + 1] = graph[now.second][now.first] + 1;
        }
        if (now.second != 0 && graph[now.second - 1][now.first] == false) {
            q.push({ now.first, now.second - 1 });
            graph[now.second - 1][now.first] = graph[now.second][now.first] + 1;
        }
        if (now.second != N - 1 && graph[now.second + 1][now.first] == false) {
            q.push({ now.first , now.second + 1 });
            graph[now.second + 1][now.first] = graph[now.second][now.first] + 1;
        }
    }
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int max=0;

    std::cin >> M >> N;

    graph.resize(N, std::vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> graph[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (graph[i][j] == 1)
                q.push({ j, i });

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                std::cout << -1;
                return 0;
            }
            max = std::max(max, graph[i][j] - 1);
        }
    }

    std::cout << max;

    return 0;
}