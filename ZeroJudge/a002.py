while True:
	try:
		s = input().split()
		i,j = int(s[0]),int(s[1])
		print(i+j)
	except:
		break