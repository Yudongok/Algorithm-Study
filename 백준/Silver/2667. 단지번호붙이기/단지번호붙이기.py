from collections import deque

N = int(input())
graph = []
visited = []
# 각 단지별 집의 수 리스트
results = []
# visited를 문제 <그림2>와 같이 만들기 위한 변수
count = 0

for i in range(N):
    # 입력받을 때 공백이 없으므로
    graph.append(list(map(int, input().strip())))
    visited.append([0] * N)
    
def bfs(x, y):
    global count
    visited[x][y] = count
    
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx<0 or nx>=N or ny<0 or ny>=N:
            continue
        if graph[nx][ny] == 1 and visited[nx][ny] == 0:
            bfs(nx, ny)
        else:
            continue
        
for i in range(N):
    for j in range(N):
        if graph[i][j] == 1 and not visited[i][j]:
            count += 1
            bfs(i, j)

# visited배열에서 결과 확인
for k in range(1, count + 1):
    num = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] == k:
                num += 1
    results.append(num)

results.sort()

print(count)
for i in results:
    print(i)

        