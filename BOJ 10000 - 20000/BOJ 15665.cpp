#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

int M, N;
std::vector<int> v, sum;

void func() {
	if (sum.size() == M) {
		for (int i = 0; i < M; i++) {
			std::cout << sum[i] << ' ';
		}
		std::cout << '\n';

		return;
	}

	for (int i = 0; i < v.size(); i++) {
		sum.push_back(v[i]);
		func();
		sum.pop_back();
	}
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int input;

	std::cin >> N >> M;

	std::set<int> s;

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		s.insert(input);
	}

	v.assign(s.begin(), s.end());

	func();

	return 0;
}