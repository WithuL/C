# # 3.2.1
# import math
# a=7.0
# b=8.0
# c=9.0
# h=(a+b+c)/2
# s=math.sqrt(h*(h-a)*(h-b)*(h-c))
# print(s)

# #让用户输入出生月和日，然后计算出接下来的生日举例今天还有多少天？
# import datetime
# today=datetime.date.today()
# month=int(input("请问你是在哪一月份出生?:"))
# day=int(input("请问你是在那一天出生:"))
# birthday=datetime.date(today.year,month,day)
# if birthday<today:
#     birthday=datetime.date(today.year+1,month,day)
# diff=birthday-today
# if diff.days==0:
#     print("生日快乐")
# else:
#     print("再过"+str(diff.days)+"就是你的生日了")

# #例9
# a=123
# b=321
# t=a
# a=b
# b=t
# print(a)
# print(t)
# print(b)

##链式赋值语句
# x=y=1
# del x
# print(x,y)

# import math
# a=1
# b=2
# x=1.5
# print((1/2)*math.sin(a*(x+1)+b))

# #输入圆的半径r，计算并输出圆的周长和面积
# import math
# r=float(input("请输入圆的半径"))
# l=2*math.pi*r
# s=math.pi*r**2
# print("圆的周长为",l)
# print("圆的面积为",s)

# #请设计一个简单的程序询问用户的年龄，如果年龄大于等于18岁就告诉他今年成年了，如果小于18岁就告诉他还差几岁成年。
# age=int(input("您的年龄为："))
# if age>=18:
#     print("您已成年")
# if age<18:
#     diff=str(18-age)
#     print("您还差"+str+"岁成年")

# def getValue(b,r,n):
#     v=b*((1+r)**n)
#     return v
# total=getValue(1000,5,5)
# print(total)

# a=int(input("请输入a"))
# b=int(input("请输入b"))
# if(a<b):
#     t=a
#     a=b
#     b=t
# print("a")

# name='alex'
# print('{0} am {1}'.format('i',name))

# import math
# x=float(input("请输入x"))
# if x>=0:
#     y=math.sin(x)+2*math.sqrt(x+math.exp(4))-(x+1)**3

mark=int(input("请输入百分数"))