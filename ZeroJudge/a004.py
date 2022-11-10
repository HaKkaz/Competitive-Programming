import sys
for i in sys.stdin:
	i=int(i)
	if ((i%4==0) and (i%100!=0)) or (i%400==0):
		print('閏年')
	else:
		print('平年')