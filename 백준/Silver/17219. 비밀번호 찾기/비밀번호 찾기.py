import sys
input = sys.stdin.readline

site = {}

N, M = map(int, input().split())

for i in range(N):
    key, value = input().split()
    site[key] = value
    
for j in range(M):
    find_site = input().rstrip()
    print(site[find_site])