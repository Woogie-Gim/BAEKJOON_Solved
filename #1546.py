n = int(input()) # 수 입력받기

a = list(map(int, input().split())) # 리스트 입력받기

M = max(a) # 조작하기로한 자기 점수 중 최댓값

Sum = 0 # 조작된 총점 구하기 위한 초기 값

for i in range(n):
    a[i] = a[i] / M * 100 # 문제조건에 의해 모든 점수를 조작
    Sum += a[i] # 총합으로 더해줌

print(Sum / n) # 다시 구해진 리스트 총합에서 과목 수를 나눠 평균 구하기