#include <iostream>
#include <vector>
#include <queue>

int K;
std::vector<bool> check;

void bfs(std::pair<int, int> now) {
	std::queue<std::pair<int, int>> q;
	q.push(now);
	check[now.first] = true;

	while (!q.empty()) {
		if (now.first == K) {
			std::cout << now.second;
			return;
		}
		now = q.front();
		q.pop();

		if (now.first - 1 >= 0 && !check[now.first - 1]) {
			q.push({ now.first - 1, now.second + 1 });
			check[now.first - 1] = true;
		}
		if (now.first + 1 <= 200000 && !check[now.first + 1]){
			q.push({ now.first + 1, now.second + 1 });
			check[now.first + 1] = true;
		}
		if (now.first * 2 <= 200000 && !check[now.first * 2]){
			q.push({ now.first * 2, now.second + 1 });
			check[now.first * 2] = true;
		}
	}
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N;

	std::cin >> N >> K;

	check.resize(200001, false);

	if (K == 0) std::cout << N;
	else	bfs({ N, 0 });

	return 0;
}