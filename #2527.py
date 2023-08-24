for i in range(4):
    startx1, starty1, endx1, endy1, startx2, starty2, endx2, endy2 = map(int, input().split())

    if endx1 < startx2 or endx2 < startx1 or starty1 > endy2 or endy1 < starty2:
        print('d')
        continue
    elif startx1 == endx2 or startx2 == endx1:
        if endy1 == starty2 or endy2 == starty1:
            print('c')
            continue
        else:
            print('b')
            continue
    elif endy1 == starty2 or endy2 == starty1:
        print('b')
        continue
    else:
        print('a')
        continue