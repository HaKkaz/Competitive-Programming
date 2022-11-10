arr = sorted(list(map(int,input().split())))
print(3 if len(set(arr)) == 1 else (2 if arr[0] == arr[1] or arr[1] == arr[2] else 1), *sorted(list(set(arr)))[::-1])