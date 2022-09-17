n = int(input())
none = list(map(int,input().split()))

for x in range(1,n+1):
	if n-x+1 not in none:
		print(f"No. {(n-x+1)}")
