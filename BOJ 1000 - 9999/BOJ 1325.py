import sys
from collections import deque

def bfs(com, start):
    cnt = 0
    check = [False] * len(com)
    check[start] = True
    q = deque([start])
    q.append(start)
    while q:
        now = q.popleft()
        cnt += 1
        for i in com[now]:
            if not check[i]:
                q.append(i)
                check[i] = True
    return cnt

if __name__ == '__main__': 
    N, M = map(int, sys.stdin.readline().split())
    
    com = [[] for _ in range(N + 1)]
    
    for i in range(M):
        A, B = map(int, sys.stdin.readline().split())
        com[B].append(A)
    
    max = 0
    res = []
    for i in range(N):
        cnt = bfs(com, i + 1)
        if cnt > max:
            res = [i + 1]
            max = cnt
        elif cnt == max:
            res.append(i + 1)
    print(*res)