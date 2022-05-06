"""
NOTICE : This code cannot AC, but its correct. 
Time complexity and Space complexity is O(N^2)
"""

n,U = map(int,input().split())
farm = [list(map(int,input().split())) for _ in range(n)]

dp = [[0 for __ in range(n+1)] for _ in range(n+1)] # dp[i][j] indicate the max square area of (i,j), (i,j) is the right-bottom corner of square
psum = [[0 for __ in range(n+1)] for _ in range(n+1)] # 2-D prefix sum

ans = 0
for i in range(1,n+1):
	for j in range(1,n+1):
		psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + farm[i-1][j-1]
		if farm[i-1][j-1] == -1:
			dp[i][j] = 0
		else:
			mn = min(dp[i-1][j] , dp[i][j-1])
			if farm[i-mn-1][j-mn-1] != -1:
				dp[i][j] = mn + 1
			else:
				dp[i][j] = mn

		h = dp[i][j]
		cost = psum[i][j] - psum[i-h][j] - psum[i][j-h] + psum[i-h][j-h]
		if cost <= U and ans < h**2:
			ans = h**2

print(ans)
