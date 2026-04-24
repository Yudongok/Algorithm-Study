def solution(array, commands):
    start = 0
    end = 0
    target = 0
    new_arr = []
    answer = []
    for i in commands:
        start = i[0]
        end = i[1]
        target = i[2]
        for j in range(start-1, end):
            new_arr.append(array[j])
        new_arr.sort()
        answer.append(new_arr[target-1])
        new_arr = []
    return answer