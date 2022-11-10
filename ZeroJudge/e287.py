n,m = map(int,input().split())

tab=[]
vis = [[0]*m for _ in range(n)]
ans=0

for i in range(n):
	tab.append(list(map(int,input().split())))

Min,sx,sy = 10000000,-1,-1

for i in range(n):
	for j in range(m):
		if tab[i][j] < Min:
			Min,sx,sy = tab[i][j],i,j


dd = [(0,1) , (1,0) , (-1,0) , (0,-1)]
while True:
	vis[sx][sy] = 1
	ans += tab[sx][sy]

	Minn,nx,ny = 10000000,-1,-1
	for d in dd:
		xx = sx + d[0]
		yy = sy + d[1]
		if xx >= 0 and xx < n and yy >= 0 and yy < m and vis[xx][yy] == False and tab[xx][yy] < Minn:
			Minn,nx,ny = tab[xx][yy],xx,yy

	if Minn == 10000000:
		break

	sx,sy = nx,ny


print(ans)