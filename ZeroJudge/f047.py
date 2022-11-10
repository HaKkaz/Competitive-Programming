strs = input().split()
ans = [list() for _ in range(3)]
for i in range(len(strs)):
    ans[i%3].append(strs[i])
for _ in range(3):
    print(*ans[_])