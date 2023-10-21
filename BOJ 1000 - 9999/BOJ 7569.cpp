#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int M, N, H, x[6] = { -1,1,0,0,0,0 }, y[6] = { 0,0,-1,1,0,0 }, z[6] = { 0,0,0,0,-1,1 };
std::vector<std::vector<std::vector<int>>> graph;
std::queue<std::vector<int>> q;

void bfs() {
    std::vector<int> now;

    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ax = now[0] + x[i], ay = now[1] + y[i], az = now[2] + z[i];

            if (ax >= 0 && ax < M && ay >= 0 && ay < N && az >= 0 && az < H && !graph[az][ay][ax]) {
                q.push({ ax, ay, az });
                graph[az][ay][ax] = graph[now[2]][now[1]][now[0]] + 1;
            }
        }
    }
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int max = 0;

    std::cin >> M >> N >> H;

    graph.resize(H, std::vector<std::vector<int>>(N, std::vector<int>(M)));

    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                std::cin >> graph[i][j][k];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                if (graph[i][j][k] == 1)
                    q.push({ k, j, i });

    bfs();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (graph[i][j][k] == 0) {
                    std::cout << -1;
                    return 0;
                }
                max = std::max(max, graph[i][j][k] - 1);
            }
        }
    }

    std::cout << max;

    return 0;
}