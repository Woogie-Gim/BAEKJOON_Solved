word = str(input())

arr = []

for i in range(1, len(word)):
    word1 = word[:i][::-1]
    for j in range(i, len(word) - 1):
        word2 = word[i:j + 1][::-1]
        word3 = word[j + 1:][::-1]

        arr.append(word1 + word2 + word3)

arr.sort()

print(arr[0])