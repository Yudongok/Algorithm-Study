import sys
import heapq  # 가장 작은 값을 항상 맨 앞으로 뺴줌

input = sys.stdin.readline

N = int(input())
M = int(input())

# 2차원 배열 대신 '인접 리스트' 사용
# 메모리를 아끼고, 0번부터 N번까지 다 검사하지 않고 연결된 버스만 확인하기 위함
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    i, k, j = map(int, input().split())
    graph[i].append((k, j))

a, b = map(int, input().split())


def dijkstra(start):
    distances = [float("inf")] * (N + 1)
    distances[start] = 0

    q = []
    heapq.heappush(q, (0, start))

    while q:
        dist, now = heapq.heappop(q)
        if distances[now] < dist:
            continue
        for next_node, next_cost in graph[now]:
            cost = dist + next_cost

            if cost < distances[next_node]:
                distances[next_node] = cost
                heapq.heappush(q, (cost, next_node))
    return distances


result = dijkstra(a)
print(result[b])
