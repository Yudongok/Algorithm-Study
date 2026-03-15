a, b, c, d, e = map(int, input().split())

k = (a**2 + b**2 + c**2 + d**2 + e**2) % 10

print(k)