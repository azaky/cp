import math, collections

def pos(x):
    if x == 1:
        return (0, 0)
    s = (int(math.floor(math.sqrt(x))) - 1) / 2 * 2 + 1
    t = s - 2
    d = (x - s * s + s) / (s + 1)
    h = (s + 1) / 2
    if d == 0:
        return (h - 1, 1 - h)
    elif d == 1:
        return (h, - h + x - s * s)
    elif d == 2:
        return (h - (x - s * s - (s + 1)), h)
    elif d == 3:
        return (-h, h - (x - s * s - (s + 1) * 2))
    elif d == 4:
        return (-h + (x - s * s - (s + 1) * 3), -h)
    else:
        raise Exception('unknown')

m = collections.defaultdict(lambda:0)
m[0, 0] = 1
i = 2
while True:
    x, y = pos(i)
    n = 0
    for ix in range(-1, 2):
        for iy in range(-1, 2):
            n += m[x + ix, y + iy]
    m[x, y] = n
    if n > 277678:
        break
        print n
    i += 1
