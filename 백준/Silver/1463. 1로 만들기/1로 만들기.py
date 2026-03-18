N = int(input())

# DP 리스트 초기화
dp = [0] * (N + 1)
for i in range(2, N + 1):
    # 기본 선택지: 1을 뺴는 경우
    dp[i] = dp[i - 1] + 1

    # 선택지: 2로 나누어 떨어지는 경우
    # i에서 1을 뺀 수에서 i까지 오는 경우 vs i에서 2를 나눈수에서 지금까지 오는 경우
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i // 2] + 1)
    # 선택지: 3으로 나누어 떨어지는 경우
    # 여기 If-else가 아닌 이중 if문이라 3가지 선택지가 모두 있는 경우도 반영됨.
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i // 3] + 1)

print(dp[N])
