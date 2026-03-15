T = int(input())

for _ in range(T):
    R, S = input().split()
    for char in S:
        print(char * int(R), end="")
    print() # 한 케이스가 끝나면 줄바꿈