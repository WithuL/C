def rob(nums):
    if len(nums)==0:
        return 0
    if len(nums)<=2:
        return max(nums)
    dp=[]
    dp.append(nums[0])
    dp.append(max(nums[0],nums[1]))
    for i in range(2,len(nums)):
        dp.append(max(dp[i-1],dp[i-2]+nums[i]))
    return dp[-1]
if __name__=="__main__":
    nums=[2,7,9,3,1]
    print(rob(nums))
