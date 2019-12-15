import  numpy as np
#Dijkstra(迪杰斯特拉)算法是求一个顶点到其他所有顶点的最短路径，是单源最短路。
graph_list = [[0,2,1,4,5,1],
              [1,0,4,2,3,4],
              [2,1,0,1,2,4],
              [3,5,2,0,3,3],
              [2,4,3,4,0,1],
              [3,4,7,3,1,0]]

def dijkstra(graph,src):
    visited=[]#已经找过的点的数组
    distance={src:0}#存储距离
    node =list(range(len(graph[0])))
    if src in node:#如果找的点在node中，
        node.remove(src)#在node中去除src
        visited.append(src)#在观光过的点中加入src
    else:
        return None
    for i in node:#让i在node中遍历
        distance[i]=graph[src][i]#distance[i]等于在邻接矩阵中起点到i的距离
    prefer=src
    while node:
        _distance =float("inf")
        for i in visited:
            for j in node:
                if graph[i][j]>0:
                    if _distance>distance[i]+graph[i][j]:#如果此时distance大于  起点到i点的最小距离，+ 从i点到j点的距离
                        _distance=distance[j]=distance[i]+graph[i][j]#就让_distance等于distance[i]+graph[i][j],顺便定义distance[J]
                        prefer=j
        visited.append(prefer)
        node.remove(prefer)
    return distance

if __name__=="__main__":
    distance=dijkstra(graph_list,0)
    print(distance)
