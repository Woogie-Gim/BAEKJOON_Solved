# 단어정렬

n = int(input())

words = [str(input()) for i in range(n)] # 단어 여러 줄에 입력 받기

words = list(set(words)) # 중복된 단어 제거 후 다시 리스트로 형 변환
words.sort() 
words.sort(key=len) # 단어의 길이를 기준으로 정렬하기

for i in words:
    print(i)