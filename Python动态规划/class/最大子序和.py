def maxSubArray(nums):
    if len(nums)==0:
        return 0
    d=[]
    d.append(nums[0])
    max_=nums[0]
    for i in range(1,len(nums)):
        if nums[i]>nums[i]+d[i-1]:
            d.append(nums[i])
        else:
            d.append(nums[i]+d[i-1])
        if max_<d[i]:
            max_=d[i]
    return max_

if __name__=="__main__":
    nums=[-2,1,-3,4,-1,2,1,-5,4]
    print(maxSubArray(nums))
