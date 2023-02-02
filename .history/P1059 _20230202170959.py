N=int(input())
N_list=input().split()
n_list=N_list
print(len(set(N_list)))
# i=0
# for i in range(1,N+1):
#     for j in range(N+1):
#         j=i+1
#         if N_list[i]==N_list[j]:
#             N_list[i]=None
#             N_list[j]=None
#     i+=1
print(sorted(N_list))