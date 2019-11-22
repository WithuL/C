def minCostClimbingStairs(cost):
    if len(cost)<=1:
        return min(cost)
    dp=[]
    dp.append(cost[0])
    dp.append(cost[1])
    for i in range(2,len(cost)+1):
        if i==len(cost):
            dp.append(min(dp[i-1],dp[i-2]))
        else:
            dp.append(min(dp[i-1]+cost[i],dp[i-2]+cost[i]))
    return dp[-1]

if __name__=="__main__":
    cost=[10,15,20]
    print(minCostClimbingStairs(cost))