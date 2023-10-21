#include <iostream>
#include <vector>

std::vector<int> sum;
std::vector<bool> check;
std::vector<std::vector<int>> graph;

void dfs(int now) {
    check[now] = true;

    for (int i = 0; i < graph[now].size(); i++) {
        if (!check[graph[now][i]]) {
            sum[graph[now][i]] = now;
            dfs(graph[now][i]);
        }
    }
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int N, input1, input2;

    std::cin >> N;

    sum.resize(N + 1);
    check.resize(N + 1);
    graph.resize(N + 1);

    for (int i = 1; i < N; i++) {
        std::cin >> input1 >> input2;
        graph[input1].push_back(input2);
        graph[input2].push_back(input1);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) std::cout << sum[i] << '\n';

    return 0;
}