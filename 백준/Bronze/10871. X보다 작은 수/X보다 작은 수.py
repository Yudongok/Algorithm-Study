N, X = map(int, input().split())
A = list(map(int, input().split()))

for num in A:
    if num < X:
        print(num, end=" ") # 줄바꿈 대신 띄어쓰기로 이어 붙이기