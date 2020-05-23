import math

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

def distance(p):
    (x, y) = pos(p)
    return abs(x) + abs(y)

print distance(277678)
