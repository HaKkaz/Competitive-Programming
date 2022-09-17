n = int(input())
ok = True
for i in range(2,n+1):
	if n % i == 0:
		ok = False
	if i * i > n:
		break
print('yes' if ok == True else 'no')