#include <iostream>
#include <vector>

std::string s;
std::vector<std::string> paper;

void countPaper(int num, int x, int y) {
    int white = 0, black = 0;

    for (int i = y; i < y + num; i++)
        for (int j = x; j < x + num; j++)
            if (paper[i][j] == '1') black++;
            else white++;

    if (white && black) {
        s += '(';
        countPaper(num / 2, x, y);
        countPaper(num / 2, x + num / 2, y);
        countPaper(num / 2, x, y + num / 2);
        countPaper(num / 2, x + num / 2, y + num / 2);
        s += ')';
    }
    else
        if (white) s += '0';
        else s += '1';
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int N;

    std::cin >> N;

    paper.resize(N);

    for (int i = 0; i < N; i++)
        std::cin >> paper[i];

    countPaper(N, 0, 0);

    std::cout << s;

    return 0;
}