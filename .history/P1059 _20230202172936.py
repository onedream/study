N=int(input())
N_list=input().split()
print(len(set(N_list)))
n_list=sorted(set(N_list))
print(sorted(N_list))
for i in range(0,len(n_list)) :
    print (n_list[i]),