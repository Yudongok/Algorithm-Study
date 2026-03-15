T = int(input())

for _ in range(T):
    quiz = input()
    score = 0
    combo = 0
    
    for q in quiz:
        if q == 'O':
            combo += 1
            score += combo
        else:
            combo = 0 # X가 나오면 콤보 초기화
            
    print(score)