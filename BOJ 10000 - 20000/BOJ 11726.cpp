#include <iostream>

int main(void)
{
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int n, dp[1001] = { 1, 1, 2 };

    std::cin >> n;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10007;
    }

    std::cout << dp[n];

    return 0;
}