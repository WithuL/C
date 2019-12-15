def maxSubArray(nums):
    if len(nums)==0:
        return 0
    d=[]
    d.append(nums[0])#在数组d后面加入num0；
    max_=nums[0]#令最大值等于NUm0；
    for i in range(1,len(nums)):#让i在1-num长度中循环
        if nums[i]>nums[i]+d[i-1]:#如果num i 的大小大于num i +他前面最大和的话，
            d.append(nums[i])#就在d后面加入Num i
        else:
            d.append(nums[i]+d[i-1])#否则就在d后面加入Numi + 它前面的最大和
        if max_<d[i]:
            max_=d[i]
    return max_

if __name__=="__main__":
    nums=[-2,1,-3,4,-1,2,1,-5,4]
    print(maxSubArray(nums))
