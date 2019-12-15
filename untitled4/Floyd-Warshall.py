#Floyd算法是求任意两点之间的距离，是多源最短路
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
        y[i] = int(y[i])#让y[I]等于y中的列数
    for i in range(len(y)):
        t[y[i] - 1] = [1000,1000,1000,1000,1000,1000]#让每个城市之间的距离为最大
    for i in range(6):
        for j in y:
            t[i][j-1]=1000#让每个城市之间的距离为最大
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
    for k in range(6):  #K为I城市到J城市最短距离中  可能更短的第三个城市
        for i in range(6): #这个是求任意两个城市之间的最短路程
            for j in range(6):
                if A [i] [j]>A[i][k]+A[k][j]:  #如果第I城市直接到J城市的距离大于I城市到K城市加K城市到J城市的距离
                   A[i][j]=A[i][k]+A[k][j] #则让第I城市到J城市的距离等于I城市到K城市加K城市到J城市的距离
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
