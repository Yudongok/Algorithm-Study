import sys
input = sys.stdin.readline

# 이 문제에서 문자열을 키(Key)로 삼아 데이터를 빠르게 분류하고 개수를 누적하기 위해 딕셔너리를 사용해야 하므로 해시(Hash) 문제임.
# 분류를 다 끝낸 후 정답을 도출하기 위해 (종류1 + 1) * (종류2 + 1) - 1이란 공식을 사용했으므로 '조합'과 '곱의 법칙' 문제임.

M = int(input())
result = []

for i in range(M):
    N = int(input())
    case = {}
    
    for j in range(N):
        name, category = input().split()
        
        if category in case:
            # 이미 존재하는 카테고리일 경우 +1
            case[category] += 1
        else:
            # 처음 보는 카테고리일 경우 value값을 1로해서 추가
            case[category] = 1
    
    total = 1   # 곱셈해야 하므로 1로 시작
    
    for count in case.values(): # 딕셔너리에 저장된 '숫자(개수)'들만 순회
        total *= (count + 1)    # 카테고리별 (입는 개수 + 안 입는 경우 1)을 누적으로 곱해줌
        
    result.append(total - 1)    # 알몸인 경우 1을 빼고 결과 리스트에 추가
        

# 리스트 순회할때 모인 정답을 차례로 출력
for ans in result:
    print(ans)