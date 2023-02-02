N=int(input())
N_list=input().split()
print(len(set(N_list)))
n_list=sorted(N_list)
i=-1
for i in range(0,N) :
    i+=1
    print (n_list[i])