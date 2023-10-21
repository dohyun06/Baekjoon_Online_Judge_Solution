#include <iostream>
#include <vector>
#include <queue>

int A, B;

int D(int x) {
    return (x * 2) % 10000;
}

int S(int x) {
    return x == 0 ? 9999 : x - 1;
}

int L(int x) {
    return (x * 10 + x / 1000) % 10000;
}

int R(int x) {
    return (x % 10) * 1000 + x / 10;
}

std::string bfs() {
    int now;
    std::string cmd;
    std::vector<bool> check(10001, false);
    std::queue<std::pair<int, std::string>> q;

    q.push({ A,"" });

    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            now = q.front().first;
            cmd = q.front().second;

            q.pop();

            if (!check[D(now)]) {
                check[D(now)] = true;
                q.push({ D(now),cmd + 'D' });
            }
            if (!check[S(now)]) {
                check[S(now)] = true;
                q.push({ S(now),cmd + 'S' });
            }
            if (!check[L(now)]) {
                check[L(now)] = true;
                q.push({ L(now),cmd + 'L' });
            }
            if (!check[R(now)]) {
                check[R(now)] = true;
                q.push({ R(now),cmd + 'R' });
            }

            if (now == B) return cmd;
        }
    }
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int T;

    std::cin >> T;

    while (T--) {
        std::cin >> A >> B;

        std::cout << bfs() << '\n';
    }

	return 0;
}