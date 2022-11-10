import sys
for i in sys.stdin:
	arr=i.split()
	a = int(arr[0])
	b = int(arr[1])
	k = (a*2+b)%3
	if k==0 :
		print('普通')
	elif k==1 :
		print('吉')
	else:
		print('大吉')