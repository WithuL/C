number1=float(input("请输入第一个数字："))
number2=float(input("请输入第二个数字："))
number3=float(input("请输入第三个数字："))
A=max(number1,number2,number3)
C=min(number1,number2,number3)
if number1<A and number1>C:
    B=number1
elif number2<A and number2>C:
    B=number2
else:
    B=number3
print('从大到小依次为：',A,B,C)