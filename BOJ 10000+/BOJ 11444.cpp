#include <iostream>
#include <vector>

std::vector<std::vector<long long>> matMul(std::vector<std::vector<long long>> mat1, std::vector<std::vector<long long>> mat2) {
	std::vector<std::vector<long long>> res(2, std::vector<long long>(2));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				res[i][j] = (res[i][j] + mat1[i][k] * mat2[k][j]) % 1000000007;

	return res;
}

std::vector<std::vector<long long>> pow(long long n) {
	if (n == 1) return { {1,1},{1,0} };

	std::vector<std::vector<long long>> res = pow(n / 2), ret = matMul(res, res);

	if (n % 2) ret = matMul(ret, { {1,1},{1,0} });

	return ret;
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	long long n, a, b = 0, c = 1;

	std::cin >> n;

	std::cout << (n ? pow(n)[0][1] : 0);

	return 0;
}