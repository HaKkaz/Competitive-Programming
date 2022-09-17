t = int(input())
for _ in range(t):
	r,c=map(int,input().split())
	ans = 0
	if c == 0:
		ans = 0
	elif r == 0:
		ans = c
	elif r == c:
		ans = r+c-1
	elif r < c:
		ans = r + c
	else:
		ans = c + c - 1
		
	print('٩(ˊᗜˋ*)و' if ans == 0 else ans)
