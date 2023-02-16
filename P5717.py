import math
n=list(map(int,input().split()))
N=sorted(n)
a=math.pow(N[0],2)
b=math.pow(N[1],2)
c=math.pow(N[2],2)
if N[0]+N[1]>N[2] :
    if a+b<c :
        print('Obtuse triangle')
    elif a+b==c :
        print('Right triangle')
    elif a+b>c:
        print('Acute triangle')
    if a==b or a==c or b==c :
        print('Isosceles triangle')
    if a==b and b==c :
        print('Equilateral triangle')
else :
    print('Not triangle')