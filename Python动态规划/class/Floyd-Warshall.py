
def setNewMap(y):
    t=[[0,2,10,5,3,1000],
       [1000,0,12,1000,1000,10],
       [1000,1000,0,1000,7,1000],
       [2,1000,1000,0,2,1000],
       [4,1000,1,1000,0,1000],
       [3,1000,1,1000,2,0]]
    if len(y) == 1 and y[0] =='0':
       return t
    for i in range(len(y)):
        y[i] = int(y[i])
    for i in range(len(y)):
        t[y[i] - 1] = [1000,1000,1000,1000,1000,1000]
    for i in range(6):
        for j in y:
            t[i][j-1]=1000
    return t
def getRoutes(path,start,end):
    rts=[]
    rts.append(start)
    i=start-1
    while path[i][end-1]!=-1:
        rts.append(path[i][end-1]+1)
        i=path[i][end-1]
    rts.append(end)
    return rts
def shortestPath(tmp):
    A=tmp
    path=[]
    for i in range(6):
        path.append([-1, -1, -1, -1, -1, -1])
    for k in range(6):
        for i in range(6):
            for j in range(6):
                if A [i] [j]>A[i][k]+A[k][j]:
                   A[i][j]=A[i][k]+A[k][j]
                   path[i][j]=k
    print('A:%s'% (A))
    print('path:%s' % (path))
    return A,path
hmap=[[0,2,10,5,3,1000],
     [1000,0,12,1000,1000,10],
     [1000,1000,0,1000,71000],
     [2,1000,1000,0,2,1000],
     [4,1000,1000,1,0,1000],
     [3,1000,1,1000,2,0]]
Y=[4]
tmp = setNewMap(Y)
a,path=shortestPath(tmp)
rts = getRoutes(path, 5, 2)
print(rts)
