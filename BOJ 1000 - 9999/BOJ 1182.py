import sys

def dfs(index, total, S, arr):
  global res
  if total == S:
    res += 1
  if index >= len(arr):
    return
  for i in range(index + 1, len(arr)):
    dfs(i, total + arr[i], S, arr)

N, S = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
res = 0

for i in range(len(arr)):
  dfs(i, arr[i], S, arr)

print(res)