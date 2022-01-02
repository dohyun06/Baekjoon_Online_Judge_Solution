#include <iostream>
#include <vector>

int sum1, sum2, sum3;
std::vector<std::vector<int>> paper;

void countPaper(int num, int x, int y) {
    int check = -2;

    for (int i = y; i < y + num; i++) {
        for (int j = x; j < x + num; j++) {
            if (paper[i][j] == -1) {
                if (check == -2) check = paper[i][j];
                else if (check != paper[i][j]) check = 2;
            }
            else if (!paper[i][j]) {
                if (check == -2) check = paper[i][j];
                else if (check != paper[i][j]) check = 2;
            }
            else {
                if (check == -2) check = paper[i][j];
                else if (check != paper[i][j]) check = 2;
            }
        }
    }

    if (check == 2) {
        countPaper(num / 3, x, y);
        countPaper(num / 3, x + num / 3, y);
        countPaper(num / 3, x + num * 2 / 3, y);

        countPaper(num / 3, x, y + num / 3);
        countPaper(num / 3, x + num / 3, y + num / 3);
        countPaper(num / 3, x + num * 2 / 3, y + num / 3);

        countPaper(num / 3, x, y + num * 2 / 3);
        countPaper(num / 3, x + num / 3, y + num * 2 / 3);
        countPaper(num / 3, x + num * 2 / 3, y + num * 2 / 3);
    }
    else
        if (check == -1) sum1++;
        else if (!check) sum2++;
        else sum3++;
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

    std::cout << sum1 << '\n' << sum2 << '\n' << sum3;

    return 0;
}