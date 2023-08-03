#1380 귀걸이
n = 1
arr = []

while n:
  n = int(input())  # n을 입력
  names = [input() for i in range(n)]  # n명의 사람 이름을 입력받아 리스트에 저장
  lst = []

  for i in range(2 * n - 1):
    a = int(input().split()[0])  # 귀걸이 번호를 입력받아 a에 저장
    lst.append(a)  # 귀걸이 번호를 lst 리스트에 추가

  lst.sort()  # lst 리스트를 오름차순으로 정렬
  for i in range(0, len(lst), 2):  # lst의 인덱스를 2씩 증가시키며 반복
    if i == (len(lst) - 1) or lst[i] != lst[i + 1]:  # 현재 번호와 다음 번호가 다를 경우 또는 마지막 번호일 경우
      arr.append(names[lst[i] - 1])  # arr 리스트에 해당 이름을 추가
      break  # 반복문을 종료

for i in range(len(arr)):
  print(i+1, arr[i]) 
