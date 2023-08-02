# 폴리오 미노

# 길이가 4 인 AAAA와 길이가 2인 BB를 '.' 과 'X' 로 이루어진 보드판에 채워넣으려고 한다.

strr = input() #보드판 입력받기

strr = strr.replace("XXXX", "AAAA")
strr = strr.replace("XX", "BB")
# 길이가 4인 XXXX와 길이가 2인 XX를 replace 함수를 통해서 바꿔준다.
# '.'은 폴리오미노로 덮으면 안되기 때문에 바꾸지 않는다

if 'X' in strr:
    print(-1)
# 만약 폴리오미노로 덮을 수 없는 경우의 수가 있을 경우 -1로 출력    
else:
    print(strr)
# 아닐 경우 폴리오미노로 덮어진 결과값 출력