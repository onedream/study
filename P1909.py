import math
n=int(input())
n1=list(map(int,input().split()))
n2=list(map(int,input().split()))
n3=list(map(int,input().split()))
n4=[]
n4.append(math.ceil(n/n1[0])*n1[1])
n4.append(math.ceil(n/n2[0])*n2[1])
n4.append(math.ceil(n/n3[0])*n3[1])
print(min(n4))