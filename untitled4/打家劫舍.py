def rob(nums):
    if len(nums)==0:
        return 0
    if len(nums)<=2:#如果数组内的元素个数小于等于2
        return max(nums)#则偷的最大的数目九尾num中的max
    dp=[]
    dp.append(nums[0])#让dp数组中加入Num0
    dp.append(max(nums[0],nums[1]))#然后再添加num0和NUM1中最大的数
    for i in range(2,len(nums)):#让i在2到数组长度中循环
        dp.append(max(dp[i-1],dp[i-2]+nums[i]))
    return dp[-1]
if __name__=="__main__":
    nums=[2,7,9,3,1]
    print(rob(nums))
