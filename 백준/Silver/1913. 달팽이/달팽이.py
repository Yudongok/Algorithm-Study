import sys

input = sys.stdin.readline

N = int(input())
target = int(input())

# arr = [[0] * N] * N으로 선언하면 안 되는 이유는 [0] * N이라는 동일한 메모리 주소를 가진 리스트를 N번 복사한다.
# arr[0][0] = 5 라고 바꾸면, 모든 행의 첫 번째 값이 다 5로 바뀌어 버리는 Shallow Copy(얕은 복사)문제가 발생한다.
# 반면 아래 방식은 for문이 돌때마다 [0] * N이라는 새로운 객체를 Heap 메모리에 할당한다.
# 따라서 arr[0], arr[1] 등 각 행이 서로 다른 메모리 주소를 참조하게 되어 독립적으로 수정이 가능하다.
arr = [[0] * N for _ in range(N)]

# 파이썬에서 그냥 /로 나눗셈하면 실수로 나옴. //로 해줘야 소수점 버리고 정수만 남김.
i = N // 2
j = N // 2
num = 1
arr[i][j] = num
num += 1

for k in range(N // 2):
    # 위로 한번
    i -= 1
    arr[i][j] = num
    num += 1
    for _ in range(2 * k + 1):
        # 오른쪽
        j += 1
        arr[i][j] = num
        num += 1

    for _ in range(2 * k + 2):
        # 아래
        i += 1
        arr[i][j] = num
        num += 1

    for _ in range(2 * k + 2):
        # 왼쪽
        j -= 1
        arr[i][j] = num
        num += 1

    for _ in range(2 * k + 2):
        # 위쪽
        i -= 1
        arr[i][j] = num
        num += 1

for r in range(N):
    for c in range(N):
        if arr[r][c] == target:
            ans_i, ans_j = r + 1, c + 1
        print(arr[r][c], end=" ")
    print()

print(ans_i, ans_j)
