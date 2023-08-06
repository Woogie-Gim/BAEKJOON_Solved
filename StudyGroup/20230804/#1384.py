group_count = 1
results = []

while True:
    G2 = []
    N = int(input())
    if N == 0:
        break
    G = []
    for i in range(N):
        Person = input().split()
        G.append(Person)
    G2.append(G)

    group_result = []
    for j in range(len(G2[0])):
        bad = -1
        if 'N' in G2[0][j]:
            nasty = G2[0][j].count('N')
            for k in range(nasty):
                bad = G2[0][j].index('N', bad + 1)
                badp = (len(G2[0]) + j - bad) % len(G2[0])
                if G2[0][j][0] != G2[0][badp][0]:
                    group_result.append(f'{G2[0][badp][0]} was nasty about {G2[0][j][0]}')
    if not group_result:
        group_result.append("Nobody was nasty")

    result = [f'Group {group_count}']
    result.extend(group_result)
    results.append(result)

    group_count += 1

for i, result in enumerate(results):
    for line in result:
        print(line)
    if i < len(results) - 1:
        print()