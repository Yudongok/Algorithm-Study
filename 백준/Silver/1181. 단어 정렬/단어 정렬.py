num = int(input())
arr = []

# 문자열 입력받기
for i in range(num):
    text = input()
    arr.append(text)

# 중복 제거
arr = list(set(arr))

# key를 이용하면 우선순위가 생김. 정렬: (1) 길이 기준으로 정렬, (2) 길이가 같으면 사전순 정렬
arr.sort(key=lambda x: (len(x), x))

# 결과 출력
for word in arr:
    print(word)
