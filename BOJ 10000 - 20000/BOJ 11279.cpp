#include <iostream>
#include <queue>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, input;
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;

	std::cin >> N;

	while (N--) {
		std::cin >> input;
		if (input) pq.push(input);
		else {
			if (pq.empty()) std::cout << 0 << '\n';
			else {
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}