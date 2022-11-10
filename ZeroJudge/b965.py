def turn(at):
    a1 = [[0]*len(at) for i in range(len(at[0]))]
    for row in range(len(at)):
        for col in range(len(at[0])):
            nr = len(at[0]) - col - 1
            nc = row
            a1[nr][nc] = at[row][col]
    return a1

def flip(af):
    for k in range(len(af)//2):
        af[k],af[len(af)-k-1] = af[len(af)-k-1],af[k]
    return af

while True:
    try:
        a,b,c= map(int,input().split())
        arr = [list(map(int,input().split())) for k in range(a)]
        r = list(map(int,input().split()))[::-1]
        for j in r:
            # print('--------------------')
            if j == 0: #旋轉
                # print('rotate')
                arr = turn(arr)
            if j == 1: #翻轉
                # print('flip')
                arr = flip(arr)

            # for ar in arr:
                # print(*ar)
            # print('--------------------')
                    
        print('{} {}'.format(len(arr),len(arr[0])))
        for l in arr:
            print(*l)
    except:
        break