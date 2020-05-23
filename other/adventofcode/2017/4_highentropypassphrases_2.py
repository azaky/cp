import collections

count = 0
for line in open('4_highentropypassphrases.txt'):
    valid = True
    v = collections.defaultdict(lambda:False)
    for word in line.split():
        s = ''.join(sorted(word))
        if v[s]:
            valid = False
            break
        v[s] = True
    if valid:
        count += 1
    else:
        print line
print count
