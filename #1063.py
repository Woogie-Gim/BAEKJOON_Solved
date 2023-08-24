k, s, N = input().split()
m = [input() for _ in range(int(N))]
ky, kx = int(k[1]), ord(k[0]) - 64
sy, sx = int(s[1]), ord(s[0]) - 64
mo={'R' : (0,1), 'L' : (0,-1), 'B' : (-1,0), 'T' : (1,0), 'RT' : (1,1), 'LT' : (1,-1), 'RB' : (-1,1), 'LB' : (-1,-1)}
for i in range(int(N)):
    y, x = mo[m[i]]
    if 1 <= ky + y < 9 and 1 <= kx + x < 9:
        if ky + y == sy and kx + x == sx:
            if 1 <= sy + y < 9 and 1 <= sx + x < 9:
                sy += y
                sx += x
                ky += y
                kx += x
        else:
            ky += y
            kx += x

print(chr(kx + 64), ky, sep='')
print(chr(sx + 64),sy, sep='')