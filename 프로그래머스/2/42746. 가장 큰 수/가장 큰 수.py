# 1. numbers의 모든 수를 str로 변경
# 2. 각 str별로 첫번째 자릿수 [0] 추출
# 3. [0] 가장 큰 수별로 정렬
# 4. 앞 숫자가 같다면 같은 애들끼리 숫자 큰거 찾는 알고리즘
# 4.1 
def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x * 3, reverse=True)
        
    # 정렬된 리스트를 하나의 문자열로 이어붙임
    answer = ''.join(numbers)
    
    return str(int(answer))