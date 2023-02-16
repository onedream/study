def factorial(n) -> int :
    sum =1
    for i in range(1,n+1) :
        sum *= i
    return sum
n=int(input())
sum=0
for i in range(1,n+1) :
    sum +=factorial(i)
print(sum)