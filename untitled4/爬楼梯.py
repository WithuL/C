def climbStairs(n):
    if n<=2:
        return n#直接返回N，N为1就只有一种，2就是2中
    a=1
    b=2
    temp=0
    for i in range(3,n+1):
        temp=a+b
        a=b
        b=temp
    return temp
if __name__=="__main__":
    n=5
    print(climbStairs(n))
