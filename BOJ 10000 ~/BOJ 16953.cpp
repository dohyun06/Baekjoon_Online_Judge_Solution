#include <iostream>
#include <queue>

long long A, B, prevSum;

int bfs(long long now) {
    std::queue<std::pair<long long, long long>> q;

    long long sum;
    q.push({ now,1 });

    while (!q.empty()) {
        now = q.front().first;
        sum = q.front().second;

        if (now * 2 == B || now * 10 + 1 == B) return sum + 1;
        else if ((now * 2 > B && now * 10 + 1 > B) && prevSum < sum) return -1;
        else {
            if (now * 2 < B) q.push({ now * 2, sum + 1 });
            if (now * 10 + 1 < B) q.push({ now * 10 + 1, sum + 1 });
        }

        prevSum = sum;
        q.pop();
    }
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    std::cin >> A >> B;

    std::cout << bfs(A);

    return 0;
}