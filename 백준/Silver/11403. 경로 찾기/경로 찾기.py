from collections import deque

N = int(input())

graph = []
results = []

for _ in range(N):
    graph.append(list(map(int, input().split())))
    
for i in range(N):
    results.append([0] * N) 

def bfs(start_node):
    queue = deque()
    queue.append(start_node)
    
    while queue:
        v = queue.popleft()
        
        for next_node in range(N):
            if graph[v][next_node] == 1 and not results[start_node][next_node]:
                results[start_node][next_node] = True
                queue.append(next_node)
                results[start_node][next_node] = 1

for i in range(N):
    bfs(i)  

for i in range(N):
    for j in range(N):
        print(results[i][j], end=' ')
    print(end='\n')