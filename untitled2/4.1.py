n=0
for i in range(1,5):
    for j in range(1,5):
        for k in range(1,5):
            if(i!=k)and(i!=j)and(j!=k):
                print(i,j,k)
                n+=1
print('能组成',n,'个互不相同且无重复的数字')
