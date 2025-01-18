#include <iostream>
#include <vector>

std::vector<bool> check;
std::vector<std::vector<int>> graph;

void dfs(int now) {
    check[now] = true;

    for (int i = 0; i < graph[now].size(); i++) {
        if (check[graph[now][i]] == false)
            dfs(graph[now][i]);
    }
}

int main(void)
{
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int N, M, input1, input2, sum=0;
    std::vector<int> temp;


    std::cin >> N >> M;

    graph.resize(N + 1);
    check.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        std::cin >> input1 >> input2;

        graph[input1].push_back(input2);
        graph[input2].push_back(input1);
    }

    for (int i = 1; i <= N; i++) {
        if (check[i] == false) {
            dfs(i);
            sum++;
        }
    }

    std::cout << sum;

    return 0;
}