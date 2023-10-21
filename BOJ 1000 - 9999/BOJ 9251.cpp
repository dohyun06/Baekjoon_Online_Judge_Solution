#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
  std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

  std::string str1, str2;

  std::cin >> str1 >> str2;

  std::vector<std::vector<int>> dp(str1.length() + 1, std::vector<int>(str2.length() + 1));

  for (int i = 1; i < str1.length() + 1; i++)
    for (int j = 1; j < str2.length() + 1; j++)
      if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

  std::cout << dp[str1.length()][str2.length()];

  return 0;
}