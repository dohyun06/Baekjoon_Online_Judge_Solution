import sys

T = int(sys.stdin.readline())

while T:
  T -= 1
  N = int(sys.stdin.readline())
  coin = list(map(int, sys.stdin.readline().split()))
  M = int(sys.stdin.readline())
  dp = [[0 for i in range(N + 1)] for j in range(M + 1)]
  for i in range(len(coin)):
    if coin[i] <= M:
      dp[coin[i]][i + 1] = 1
    else:
      N -= 1
  for i in range(1, M + 1):
    for j in range(1, N + 1):
      if (i - coin[j - 1]) >= 0:
        for k in range(j):
          dp[i][j] += dp[i - coin[j - k - 1]][j - k] 
      else:
        dp[i][j] += dp[i][j - 1]
  print(dp[M][N])