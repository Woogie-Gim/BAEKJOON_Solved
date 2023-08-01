n = int(input()) # 수 입력받기

lst = [] # 빈리스트에 입력받은 수 들을 추가하여 리스트화 한다

for _ in range(n) : # N개의 수까지 반복문 실행
    lst.append(int(input())) # 빈리스트에 첫 째줄 부터 N개의 수까지 입력바는다

# 값이 새로 추가되기 때문에 값이 추가 될 때 사용하기 용이한 삽입 정렬로 정렬

result = [0] * n # 입력받은 리스트와 같은 크기의 다른 리스트를 만들어줌

for i in range(len(lst)) :
    result[i] = lst[i]
    for j in range(i, -1, 1):
        if result[j-1] > result[j]:
            result[j-1], result[j] = result[j], result[j-1]
        else:
            break

            
for i in lst : 
    print(i)