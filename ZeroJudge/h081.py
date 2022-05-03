n,D = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
x = a[0]
for i in range(1,n):
	if x > 0 and a[i] >= x + D:
		ans += (a[i] - x)
		x = -a[i]
	if x < 0 and a[i] <= -x - D:
		x = a[i]
print(ans)

