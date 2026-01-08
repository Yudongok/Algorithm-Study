import heapq
import sys

# 입력 속도를 높이기 위해 sys.stdin.readline 사용 (C++의 cin.tie(0) 역할)
input = sys.stdin.readline

N = int(input())
max_heap = []
results = []

for _ in range(N):
    n = int(input()) # 매번 숫자를 입력받음
    
    if n == 0: # 입력이 0이면 가장 큰 값을 출력
        if not max_heap: # 힙이 비어있을 때 예외 처리
            results.append(0)
        else:
            # (-n, n) 튜플에서 원래의 값인 n (인덱스 1)을 꺼냄
            priority, value = heapq.heappop(max_heap)
            results.append(value)
    else: # 입력이 0이 아니면 힙에 추가
        heapq.heappush(max_heap, (-n, n))
        
for res in results:
    print(res)