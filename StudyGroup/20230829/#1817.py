n, m = map(int,input().split())
cnt = 0
if n == 0 : 
    print(0)
else :
    box = list(map(int, input().split()))
    W = 0
    cnt = 1
    for box in box:
        if box+W <= m :
            W += box
        else :
            W = box
            cnt +=1
    print(cnt)