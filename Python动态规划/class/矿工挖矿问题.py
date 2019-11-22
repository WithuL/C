import copy

def good(n,w,g=[],p=[]):
    arr=[0]*w
    for i in range(w):
        if (i+1)>=p[0]:
            arr[i]=g[0]
    res=copy.deepcopy(arr)
    print(res)
    for i in range(1,n):
        for j in range(w):
            if(j+1)<p[i]:
                arr[j]=res[j]
            else:
                t=0 if (j-p[i])<0 else j - p[i]
                arr[j]=max(res[j],res[t]+g[i])
        res=copy.deepcopy(arr)
        print(res)
    return res.pop()
if __name__=="__main__":
    res=good(5,10,[400,500,200,300,350],[5,5,3,4,3])
    print(res)
