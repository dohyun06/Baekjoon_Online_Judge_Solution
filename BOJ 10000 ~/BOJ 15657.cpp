#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> number, seq;

void backtracking(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++)
            std::cout << seq[i] << ' ';
        std::cout << '\n';
    }

    else {
        for (int i = 0; i < N; i++) {
            if (!count || seq[count - 1] <= number[i]) {
                seq.push_back(number[i]);
                backtracking(count + 1);
                seq.pop_back();
            }
        }
    }
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;

    number.resize(N);

    for (int i = 0; i < N; i++) std::cin >> number[i];

    std::sort(number.begin(), number.end());

    backtracking(0);

    return 0;
}