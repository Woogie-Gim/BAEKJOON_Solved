n = input()
cnt = 0 

while len(n) > 1: 
    cnt += 1 
    ans = 0
    for i in n:
        ans += int(i) 
    n = str(ans) 

print(cnt) 

if int(n) % 3 == 0: 
      print("YES")
else:
       print("NO")