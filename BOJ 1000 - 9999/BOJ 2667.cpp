#include <iostream>
#include <vector>
#include <algorithm>

int N, sum;
std::vector<int> house;
std::vector<std::string> graph;

void dfs(int x, int y) {
    if (graph[y][x] != '0') {
        graph[y][x] = '0';
        house[sum - 1]++;

        if (x != 0) dfs(x - 1, y);
        if (x != N - 1) dfs(x + 1, y);
        if (y != 0) dfs(x, y - 1);
        if (y != N - 1) dfs(x, y + 1);
    }
    else return;
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    std::string s;

    std::cin >> N;

    graph.resize(N);

    for (int i = 0; i < N; i++) {
        std::cin >> s;
        graph[i] = s;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != '0') {
                house.push_back(0);
                sum++;
                dfs(j, i);
            }
        }
    }
    std::sort(house.begin(), house.end());

    std::cout << sum << '\n';
    for (int i = 0; i < house.size(); i++)
        std::cout << house[i] << '\n';

    return 0;
}