from collections import deque

def solve():
    N, K = map(int, input().split())
    
    MAX = 100001
    # visited를 0으로 초기화 할 경우 만약 아직 방문되지 않은 곳도 0이고 시작 지점도 0이므로 구분이 안 된다. 
    # 나중에 다시 시작점으로 돌아오는 경로가 계산될 때, 이미 방문했는지 확인하기 까다로워진다.
    visited = [-1] * MAX
    
    # 애초에 deque는 반복 가능한 객체(리스트, 튜플, 문자열)를 인자로 받기 때문에 deque(N)을 하면 에러가 난다.
    queue = deque([N])
    # 시작부터 만났을 경우 0초이므로 0으로 만들어줌.
    visited[N] = 0
    
    while queue:
        curr = queue.popleft()
        
        if curr == K:
            print(visited[curr])
            return
        
        for next_pos in (curr-1, curr+1, curr*2):
            if 0 <= next_pos < MAX and visited[next_pos] == -1:
                visited[next_pos] = visited[curr] + 1
                queue.append(next_pos)
                
solve()