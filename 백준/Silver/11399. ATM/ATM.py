N = int(input())
P = list(map(int, input().split()))

P.sort()

results = 0
for i in range(N):
    for j in range(i+1):
        results += P[j]

print(results)