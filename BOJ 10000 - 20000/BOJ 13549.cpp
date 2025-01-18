#include <deque>
#include <iostream>
#include <vector>

int              N, K;
std::vector<int> sec(200001, 100001);

void bfs(int now) {
  std::deque<int> dq;

  dq.push_back(now);

  while (!dq.empty()) {
    now = dq.front();
    dq.pop_front();

    if (now == K) {
      std::cout << sec[now];
      return;
    }

    if (now * 2 < 200001 && sec[now] < sec[now * 2]) {
      dq.push_front(now * 2);
      sec[now * 2] = sec[now];
    }
    if (now + 1 < 200001 && sec[now] + 1 < sec[now + 1]) {
      dq.push_back(now + 1);
      sec[now + 1] = sec[now] + 1;
    }
    if (now > 0 && sec[now] + 1 < sec[now - 1]) {
      dq.push_back(now - 1);
      sec[now - 1] = sec[now] + 1;
    }
  }
}

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  std::cin >> N >> K;
  sec[N] = 0;

  bfs(N);

  return 0;
}