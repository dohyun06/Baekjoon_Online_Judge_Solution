#include <iostream>
#include <vector>

int sum1, sum2;
std::vector<std::vector<int>> paper;

void countPaper(int num, int x, int y) {
    int white = 0, blue = 0;

    for (int i = y; i < y + num; i++)
        for (int j = x; j < x + num; j++)
            if (paper[i][j]) blue++;
            else white++;

    if (white && blue) {
        countPaper(num / 2, x, y);
        countPaper(num / 2, x + num / 2, y);
        countPaper(num / 2, x, y + num / 2);
        countPaper(num / 2, x + num / 2, y + num / 2);
    }
    else
        if (!blue) sum1++;
        else sum2++;
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    paper.resize(N, std::vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> paper[i][j];

    countPaper(N, 0, 0);

    std::cout << sum1 << '\n' << sum2;

    return 0;
}