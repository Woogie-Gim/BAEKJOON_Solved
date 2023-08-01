# 서로 다른 n개 중에서 r개를 선택하는 경우의 수 이기 때문에
# nCr = n! / (n-r)!r!
# 팩토리얼 이라는 함수를 정의하여 nCr 을 구현해줄 예정

def fact(value):
    n = 1

    for i in range(1, value + 1):
        n *= i
    return n

# 자기 자신부터 1까지의 모든 수의 곱


T = int(input()) # 테스트 케이스 입력

for _ in range(T): # 테스트 케이스 별로 확인하기 위해 반복문
    n, m = map(int, input().split())
    bridge = fact(m) / (fact(n) * fact(m - n)) # nCr
    print(int(bridge))
    # 계산 값이 float로 출력되기 때문에 정수형으로 형변환

