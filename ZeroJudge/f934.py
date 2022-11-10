mn,ans = 10000000,0
for val in list(map(int,input().split())):
    ans,mn = max(ans , val - mn),min(mn,val)
print(ans)