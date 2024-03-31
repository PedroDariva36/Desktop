
s = str(input())
n = int(input())

qnt = [0] * 112345

m = {
    'a' : 0,
    'b' : 0,
    'c' : 0,
    'd' : 0,
    'e' : 0,
    'f' : 0,
    'g' : 0,
    'h' : 0,
    'i' : 0,
    'j' : 0,
    'k' : 0,
    'l' : 0,
    'm' : 0,
    'n' : 0,
    'o' : 0,
    'p' : 0,
    'q' : 0,
    'r' : 0,
    's' : 0,
    't' : 0,
    'u' : 0,
    'v' : 0,
    'w' : 0,
    'x' : 0,
    'y' : 0,
    'z' : 0
}

MOD = 10**9 + 7

for i in range(len(s)-1, -1, -1):
    m[s[i]] += 1
    for j in range(97, ord(s[i]), 1):
        qnt[i]+=m[chr(j)]

ans = 0
aux = 0
for i in range(len(s)):
    for k, v in m.items():
        if (k < s[i]):
            aux += v
    ans += (n * qnt[i])
            
ans += aux * (((n-1) * n) // 2)


print(int(ans) % MOD)