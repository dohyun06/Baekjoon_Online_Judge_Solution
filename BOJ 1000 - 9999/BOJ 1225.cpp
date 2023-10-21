#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	long long sum = 0;
	std::string A, B;

	std::cin >> A >> B;

	for (int i = 0; i < A.length(); i++)
		for (int j = 0; j < B.length(); j++)
			sum += (A[i] - '0') * (B[j] - '0');

	std::cout << sum;

	return 0;
}