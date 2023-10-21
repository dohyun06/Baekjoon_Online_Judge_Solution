#include <iostream>
#include <string>
#include <deque>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int T, n, num = 0;
	std::string p, x;
	std::deque<int> d;

	std::cin >> T;

	while (T--) {
		std::cin >> p >> n >> x;

		bool back = false;
		std::string sum;

		for (int i = 1; i < x.length(); i++) {
			if (x[i] >= '0' && x[i] <= '9') num = num * 10 + (x[i] - '0');
			else if (num) {
				d.push_back(num);
				num = 0;
			}
		}
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') back = back ? false : true;
			else {
				if (d.empty()) {
					sum = "error";
					break;
				}
				if (!back) d.pop_front();
				else d.pop_back();
			}
		}

		if (sum[0] != 'e') {
			int size = d.size();
			sum = '[';

			for (int i = 0; i < size; i++) {
				if (!back) {
					sum += std::to_string(d.front());
					d.pop_front();
				}
				else {
					sum += std::to_string(d.back());
					d.pop_back();
				}

				if (i != size - 1) sum += ',';
			}
			sum += ']';
		}

		std::cout << sum << '\n';
	}

	return 0;
}