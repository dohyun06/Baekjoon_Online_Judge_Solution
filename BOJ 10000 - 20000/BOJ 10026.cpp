#include <iostream>
#include <vector>

int N, sum;
char color;
std::vector<std::string> graph1, graph2;

void dfs1(int x, int y) {
    if (graph1[y][x] != 'F' && color == graph1[y][x]) {
        graph1[y][x] = 'F';

        if (x != 0) dfs1(x - 1, y);
        if (x != N - 1) dfs1(x + 1, y);
        if (y != 0) dfs1(x, y - 1);
        if (y != N - 1) dfs1(x, y + 1);
    }
    else return;
}

void dfs2(int x, int y) {
    if (graph2[y][x] != 'F') {
        if (color == graph2[y][x] || (color == 'R' && graph2[y][x] == 'G') || (color == 'G' && graph2[y][x] == 'R')) {
            graph2[y][x] = 'F';

            if (x != 0) dfs2(x - 1, y);
            if (x != N - 1) dfs2(x + 1, y);
            if (y != 0) dfs2(x, y - 1);
            if (y != N - 1) dfs2(x, y + 1);
        }
    }
    else return;
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    std::string s;

    std::cin >> N;

    graph1.resize(N);

    for (int i = 0; i < N; i++) {
        std::cin >> s;
        graph1[i] = s;
    }
    graph2 = graph1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph1[i][j] != 'F') {
                sum++;
                color = graph1[i][j];
                dfs1(j, i);
            }
        }
    }
    std::cout << sum << ' ';

    sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph2[i][j] != 'F') {
                sum++;
                color = graph2[i][j];
                dfs2(j, i);
            }
        }
    }

    std::cout << sum;

    return 0;
}