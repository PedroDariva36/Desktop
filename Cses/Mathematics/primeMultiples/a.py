n, k = map(int ,input().split())
p = list(map(int, input().split()))

asw = 0   

for i in range(1, 1<<len(p)):
    mul = 1
    c = 0

    for j in range(len(p)):
        if(i & (1 << j)):
            mul *= p[j]
            c += 1

    
    if(c%2 == 1):
        asw += (n // mul)
    else:
        asw -= (n // mul)



print(asw)
