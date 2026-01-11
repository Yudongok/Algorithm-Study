import heapq
import sys

input = sys.stdin.readline

heap = []
out = []

N = int(input())

for _ in range(N):
    x = int(input())
    if x == 0:
        if not heap:
            out.append(0)
        else:
            priority, value = heapq.heappop(heap)
            out.append(value)
    elif x < 0:
        heapq.heappush(heap, (-x, x))
    else:
        heapq.heappush(heap, (x, x))

for _ in out:
    print(_)