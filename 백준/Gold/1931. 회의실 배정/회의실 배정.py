import sys
import heapq  # heapq는 독립적인 내장 모듈임
from collections import deque

input = sys.stdin.readline

stack = deque()
arr = []  # heapq는 일반 리스트를 바탕으로 동작함 heapq() 안 해도 됨.
result = 0

N = int(input())

for i in range(N):
    start_time, end_time = map(int, input().split())
    heapq.heappush(arr, (end_time, start_time))

# 이 문제 핵심 로젝은 끝나는 시간에 포커싱을 하는 것이다. 난 회의에 걸리는 시간이 짧은걸 우선순위로 둬야 한다고 생각했는데 잘못된 생각이었다.
# 예를 들어 A(1, 10) - 9, B(8, 12) - 4, C(11, 20) - 9 이렇게 3개의 회의가 있다면 B를 선택했을 시 회의를 1개밖에 하지 못한다.
# 하지만 회의가 빨리 끝나는 A를 기준으로 잡을 경우 A,C를 선택하여 2개를 할 수 있다.
# 아주 간단하게 회의실을 많이 사용하려면, 현재 시점에서 가장 빨리 끝나는 회의를 선택해야 다음 회의를 잡을 수 있는 "남은 시간"을 최대로 확보할 수 있기 때문이다.
# 즉 끝나는 시간이 빠를수록 뒤이어 올 수 있는 회의들의 기회가 많아진다. 이게 이 문제의 그리디 알고리즘 원리이다.
end_time, start_time = heapq.heappop(arr)
current_time = end_time
result += 1

# While arr is not None을 하게 되면 파이썬에서 리스트 안의 데이터가 다 빠져나가 비어있는 상태([])가 되더라도 None이 되지 않는다.
# 따라서 이 반복문은 멈추지 않고 계속 돌다가 빈 리스트에서 heappop을 하려고 시도하면 IndexError가 발생한다.
while arr:
    end_time, start_time = heapq.heappop(arr)
    if current_time <= start_time:
        result += 1
        current_time = end_time
    else:
        continue

print(result)
