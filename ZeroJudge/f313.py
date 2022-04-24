n,m,k,d=map(int,input().split())
table = list()

for _ in range(n):
    table.append( list(map(int,input().split())) )

dir = [[0,-1],[0,1],[-1,0],[1,0]]

for _ in range(d):

    tmp = [[0]*m for t in range(n)]
    dec = [[0]*m for t in range(n)]

    for x in range(n):
        for y in range(m):
            if table[x][y] == -1:
                continue;
            for d in dir:
                xx = x + d[0]
                yy = y + d[1]
                if xx < 0 or xx >= n or yy < 0 or yy >= m or table[xx][yy] == -1:
                    continue

                tmp[xx][yy] += table[x][y]//k
                dec[x][y] += table[x][y]//k

    for x in range(n):
        for y in range(m):
            if table[x][y] == -1:
                continue;
            table[x][y] -= dec[x][y]
            table[x][y] += tmp[x][y]

mx , mn = 0 , 10000000

for x in range(n):
    for y in range(m):
        if table[x][y] == -1:
            continue;
        mx = max(mx , table[x][y])
        mn = min(mn , table[x][y])

print(mn , mx , sep='\n')