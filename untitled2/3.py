a=1
b=1
tmp=2
i=1
print('请输入n阶楼梯')
d=int(input())
if d<3:
    print(d)
if d>2:
   for i in range(3,d+1):
       a=b
       b=tmp
       tmp=a+b

print(tmp)