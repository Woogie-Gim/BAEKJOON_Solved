# 체스판은 8×8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 있다.
# 가장 왼쪽 위칸 (0,0)은 하얀색이다. 체스판의 상태가 주어졌을 때, 
# 하얀 칸 위에 말이 몇 개 있는지 출력하는 프로그램을 작성하시오.

lst = []

for i in range(8):
    row = list(input())
    lst.append(row)
# 빈 리스트에 입력받은 리스트를 입력 받아서 2차원 배열 만들기

count = 0

for i in range(8):
    for j in range(8):
        if i % 2 == 0 and j % 2 == 0:
            if lst[i][j] == 'F':
                count += 1
        elif i % 2 == 1 and j % 2 == 1:
            if lst[i][j] == 'F':
                count += 1
# 2중 for문을 통해서 리스트 요소에 접근하고 인덱스에 2중 if문을 통해
# 특정 위치에 말이 놓여 있는지 확인하는 코드

print(count)