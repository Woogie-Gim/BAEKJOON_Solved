x = int(input())

lst = [64] # 처음 64 cm 짜리 리스트
stick = 64 # 초기 길이
count = 0

for i in range(6):    # 64는 2의 6승이므로 6번까지 반으로 쪼갤 수 있다
    stick //= 2
    lst.append(stick)
    
if x in lst :       # 리스트 안에 있는 수가 x라면 풀로 붙일 필요없이 1을 출력.
    print(1)
else :
    for i in lst :  # 리스트의 큰 요소부터 붙여나가기 위한 반복문
        if x >= i :
            x -= i
            count +=1
    print(count)