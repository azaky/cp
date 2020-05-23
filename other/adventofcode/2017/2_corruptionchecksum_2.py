checksum = 0
for line in open('2_corruptionchecksum.txt'):
    num = map(int, line.split())
    print num
    found = False
    for c in num:
        for x in num:
            if c % x == 0 and c != x:
                checksum += c / x
                found = True
    if not found:
        checksum += 1
print checksum
