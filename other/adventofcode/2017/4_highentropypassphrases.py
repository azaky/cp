import collections

count = 0
for line in open('4_highentropypassphrases.txt'):
    valid = True
    v = collections.defaultdict(lambda:0)
    for word in line.split():
        if v[word]:
            valid = False
            break
        v[word] = True
    if valid:
        count += 1
    else:
        print line
print count
