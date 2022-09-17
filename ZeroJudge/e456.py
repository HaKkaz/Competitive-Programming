arr = input().split()
for i in range(len(arr)):
	if i != len(arr)-1:
		print(f'{arr[i]} little, ',end='')
	else:
		print(f'{arr[i]} little',end='')
print(' Indians')