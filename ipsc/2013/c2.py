foo = "AIcCAYWcSeMISeCCEUOUQCKGKIYWEUeEAKKAIeeEeeACYQUFbPLTRcDPNBXNBPBJHLLTPXDdTHVZGAFZdQbDbLeWBTTRPXAIKfZVWecfTNCbCKfOXFXUQFXcXLOIKNUPVcWFLVVZTEAKJdPTa"
bar = 88767

s = 0
def n():
    global s
    s=(s*1664525+1013904223)%(1<<32)
    return s

def g(b):
    i = -1
    while True:
        i += 1
        c = foo[i] if i<145 else "HeHeHe"[i%6]
        x = ord(c) - 65 - 6*(ord(c)>90)
        for j in range(2-x%2):
            for q in range(2):
                if not b: return (((bar<<8)+228)>>(2*((x>>(2*j+1))&(3+12*(x%2)))+1-q))&1
                b -= 1

x,y = 0.,0.
while True:
    for i in range(1000):
        b=n()
        if not g(b): x, y = (b%21+x)/21, (20-b//21+y)/21
    print(x,y)
