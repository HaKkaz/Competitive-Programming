a,b,c=sorted(list(map(int,input().split())))
print('right triangle' if a*a + b*b == c*c else ('acute triangle' if a*a + b*b > c*c else 'obtuse triangle'))