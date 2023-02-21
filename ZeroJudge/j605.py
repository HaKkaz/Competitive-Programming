n = int(input())

mx_score = -100000
mx_time = 0
cnt = 0

for i in range(n):
	t,s = map(int,input().split())
	if mx_score < s:
		mx_score = s
		mx_time = t
	if s == -1:
		cnt += 1

print(max(mx_score-n-cnt*2, 0), mx_time)
