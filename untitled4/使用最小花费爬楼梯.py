def minCostClimbingStairs(cost):
    if len(cost)<=1:
        return min(cost)
    dp=[]
    dp.append(cost[0])#在dp中添加cost0
    dp.append(cost[1])#在dp中添加cost1
    for i in range(2,len(cost)+1):#让i在2，cost长度中循环
        if i==len(cost):#如果i等于了cost的长度
            dp.append(min(dp[i-1],dp[i-2]))#就在dp中添加之前两个元素中最小的那个
        else:
            dp.append(min(dp[i-1]+cost[i],dp[i-2]+cost[i]))#否则就添加两相加元素最小的那个。
    return dp[-1]#返回最后一个元素

if __name__=="__main__":
    cost=[10,15,20]
    print(minCostClimbingStairs(cost))