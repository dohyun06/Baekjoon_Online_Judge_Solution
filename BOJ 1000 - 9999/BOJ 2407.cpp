#include <iostream>
#include <string>
#include <vector>

std::string dp[101][101];

std::string add(std::string a, std::string b) {
	int index = a.length() > b.length() ? a.length() + 1 : b.length() + 1;
	std::string result;
	std::vector<int> sum(index, 0);

	while (a.length() != b.length())
		if (a.length() > b.length()) b = "0" + b;
		else a = "0" + a;

	for (int i = 0; i < index - 1; i++) {
		if (sum[i] + (a[a.length() - i - 1] - '0') + (b[b.length() - i - 1] - '0') >= 10) {
			sum[i] += (a[a.length() - i - 1] - '0') + (b[b.length() - i - 1] - '0') - 10;
			sum[i + 1]++;
		}
		else sum[i] += (int)((a[a.length() - i - 1] - '0') + (b[b.length() - i - 1] - '0'));
	}

	for (int i = sum.size() - 1; i >= 0; i--)
		if (i != sum.size() - 1 || sum[i] != 0)
			result += std::to_string(sum[i]);

	return result;
}

std::string combination(int n, int m) {
	if (n == m || m == 0) return "1";

	if (dp[n][m] != "") return dp[n][m];

	dp[n][m] = add(combination(n - 1, m - 1), combination(n - 1, m));
	return dp[n][m];
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int n, m;

	std::cin >> n >> m;

	std::cout << combination(n, m);

	return 0;
}