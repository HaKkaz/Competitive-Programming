import sys
for n in sys.stdin:
	n = int(n)
	if n == 0 : 
		break
	for x in range(0 , n) :
		if x>0 and x%7 :
			print(x,end=' ')
	print()