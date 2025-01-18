#include <iostream>
#include <vector>
#include <queue>

std::vector<bool> graph(101);
std::vector<int> ladder, snake;

int bfs() {
    int now = 1, sum = 0;
    std::queue<int> q;

    graph[now] = true;
    q.push(now);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            now = q.front();
            q.pop();

            if (now == 100) return sum;

            for (int j = 1; j <= 6; j++) {
                if (now + j <= 100 && !graph[now + j]) {
                    graph[now + j] = true;
                    if (ladder[now + j]) {
                        if (!graph[ladder[now + j]])
                            q.push(ladder[now + j]);
                    }
                    else if (snake[now + j]) {
                        if (!graph[snake[now + j]])
                            q.push(snake[now + j]);
                    }
                    else {
                        q.push(now + j);
                    }
                }
            }
        }
        sum++;
    }
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int N, M, input;

    std::cin >> N >> M;

    ladder.resize(101);
    snake.resize(101);

    for (int i = 0; i < N; i++) {
        std::cin >> input;
        std::cin >> ladder[input];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> input;
        std::cin >> snake[input];
    }

    std::cout << bfs();

    return 0;
}