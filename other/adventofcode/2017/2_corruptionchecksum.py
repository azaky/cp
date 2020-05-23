checksum = 0
for line in open('2_corruptionchecksum.txt'):
    num = map(int, line.split())
    checksum += max(num) - min(num)
print checksum
