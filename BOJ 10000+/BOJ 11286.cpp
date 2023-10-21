#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, x;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

	std::cin >> N;

	while (N--) {
		std::cin >> x;

		if (x) pq.push({ abs(x),x });
		else {
			if (pq.empty()) std::cout << 0 << '\n';
			else {
				std::cout << pq.top().second << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}