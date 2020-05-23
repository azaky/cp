
A = [ 1894607624, 1927505134, 1861486949, 2052221263, 1953703270, 1772249212, 1704106159, 1607055075, 1829198849 ]

def t(n):
    z=n
    for a in range(2,n):
        if t(a)>=a:
            if n%a==0: z//=t(a) ; z*=t(a)-1
    return min(z+1,n)

A.sort()
for i in range(4): A[i+5] ^= t(A[i+1]-A[0])>>7
z = max( t(A[0])-1, A[0]+1-t(A[0]) )
for i in range(z): A = A[1:] + A[:1]
A.insert(1,z)
for x in range(8,10**7):
    y = A[x//4]>>(18-6*(x%4))&63
    if y: print( chr(31+y) if y<60 else A[y-60], end='')
    else: break

