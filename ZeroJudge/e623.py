n = int(input())
count, p = 0, 0
for i in range(1,10000):
	for j in range(4):
		for k in range(i):
			count += 1
			if count == n:
				print(["Pen","Pineapple","Apple","Pineapple pen"][p])
				exit(0)
		p += 1
		p %= 4