n = int(input())
pts = []
for i in range(n):
    x, y = map(int,input().split())
    pts.append((x,y))

mx, mn = 0, 1000000000
for i in range(1,n):
    x1, y1 = pts[i-1]
    x2, y2 = pts[i]
    dis = abs(x1 - x2) + abs(y1 - y2)
    mx = max(mx, dis)
    mn = min(mn, dis)
print(mx, mn)
