import sys
import heapq

input = sys.stdin.readline

N = int(input())
heap = []
out = []

for _ in range(N):
    x = int(input())
    
    if x == 0:
        # heapq.heappop에서 heapq는 heapq라는 모듈안의 함수를 호출하는 형태임
        # str을 붙이는 이유는 우리가 sys.stdin.readline을 사용했으므로 리스트안의 요소가 모두 문자열이어야 함
        # else "0" 부분은 일단 아래 조건부 표현식이 삼항 연산자임. if heap은 heap이 비어있지 않으면
        # else "0"는 heap이 비어있으면 출력할 값
        out.append(str(heapq.heappop(heap)) if heap else "0")
    else:
        heapq.heappush(heap, x)
        
sys.stdout.write("\n".join(out))