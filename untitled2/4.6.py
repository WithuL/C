month=int(input("请输入截止月份："))
if month==1:
    print("第 1 月，兔子有 1 对")
elif month==2:
    print("第 1 月，兔子有 1 对")
    print("第 2 月，兔子有 1 对")
else:
    print("第 1 月，兔子有 1 对")
    print("第 2 月，兔子有 1 对")
    A=[1,1]
    for i in range(1,month-1):
        B=A[i]+A[i-1]
        A.append(B)
        print('第',(i+2),'月，兔子有',B,'对')