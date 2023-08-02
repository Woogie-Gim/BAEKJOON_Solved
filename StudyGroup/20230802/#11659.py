import sys
input = sys.stdin.readline

N, M = map(int, input().split()) # 개수 N과 합을 구해야하는 횟수 M

arr = list(map(int, input().split())) # N개의 숫자

Sumlist = [0] # 합배열 만들기
Sum = 0

for i in arr: # 입력 받은 N개의 숫자를 반복문을 통해
    Sum += i
    Sumlist.append(Sum) # 합을 구할 때 마다 합배열에 추가해주기

for i in range(M):
    a, b = map(int, input().split())  # 구간 입력 받기
    print(Sumlist[b] - Sumlist[a - 1]) # 합배열에서 구간 합 구하기
