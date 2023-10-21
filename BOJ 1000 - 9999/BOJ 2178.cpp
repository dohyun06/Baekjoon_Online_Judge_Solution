#include <iostream>
#include <vector>
#include <queue>

int M, N, sum = 1;
std::vector<std::string> graph;
std::queue<std::pair<int, int>> q;

void bfs() {
    std::pair<int, int> now;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            now = q.front();
            q.pop();

            if (now.first != 0 && graph[now.second][now.first - 1] == '1') {
                q.push({ now.first - 1, now.second });
                graph[now.second][now.first - 1] = '2';
            }
            if (now.first != M - 1 && graph[now.second][now.first + 1] == '1') {
                if (now.first + 1 == M - 1 && now.second == N - 1) return;
                q.push({ now.first + 1, now.second });
                graph[now.second][now.first + 1] = '2';
            }
            if (now.second != 0 && graph[now.second - 1][now.first] == '1') {
                q.push({ now.first, now.second - 1 });
                graph[now.second - 1][now.first] = '2';
            }
            if (now.second != N - 1 && graph[now.second + 1][now.first] == '1') {
                if (now.first == M - 1 && now.second + 1 == N - 1) return;
                q.push({ now.first , now.second + 1 });
                graph[now.second + 1][now.first] = '2';
            }
        }
        sum++;
    }
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;

    graph.resize(N);

    for (int i = 0; i < N; i++)
        std::cin >> graph[i];

    q.push({ 0,0 });
    graph[0][0] = '2';

    bfs();

    std::cout << sum + 1;

    return 0;
}