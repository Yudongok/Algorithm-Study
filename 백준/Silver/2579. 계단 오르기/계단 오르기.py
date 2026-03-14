import sys
input = sys.stdin.readline

N = int(input())
score = [0] * 301   # 계단 개수는 300 이하 자연수이므로 미리 최대로 생성
for i in range(1, N+1):
    score[i] = int(input())
    
dp = [0] * 301

# dp[0]은 계단을 오르기 전 바닥으로 처리함.
dp[1] = score[1]
dp[2] = score[1] + score[2]
dp[3] = max(score[1] + score[3], score[2] + score[3])

for i in range(4, N+1):
    # i번째 게단을 오를때 2가지 선택지가 있음. i-1에서 왔거나 i-2에서 왔거나.
    # i-1에서 왔을 경우 무조건 i-3을 밟게됨. 따라서 그걸 반영해서 비교
    # i-2에서 왔을 경우는 i-2까지의 dp값을 이용해서 계산
    dp[i] = max(dp[i-3] + score[i-1] + score[i], dp[i-2] + score[i])
    
print(dp[N])