n,s = map(int,input().split())
v = [None] * n
for i in range(n):
    a,b = input().split()
    v[i] = (int(b),a)
v.sort(reverse=True)

c = 0
u = []
for b,a in v:
    if c+b <= s:
        c += b
        u.append(a)

if c != s:
    u = []

print(len(u))
for z in u:
    print(z)
