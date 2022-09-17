from collections import defaultdict
dic = defaultdict(int)
n,k = map(int,input().split())
ans = 0
for x in list(map(int,input().split())):
    dic[x] += 1

for item in dic.items():
    ans += item[1]//k 
print(ans)