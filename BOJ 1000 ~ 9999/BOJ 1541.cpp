#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int num=0, sum=0, flag=1;
	std::string s;

	std::cin >> s;

	for (char c : s) {
		if (c == '+') {
			sum += num;
			num = 0;
		}
		else if (c == '-') {
			flag = -1;
			sum += num;
			num = 0;
		}
		else {
			num = num * 10 + (c - '0') * flag;
		}
	}
	std::cout << sum + num;

	return 0;
}