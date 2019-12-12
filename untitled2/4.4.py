print("请按照提示输入年月日!!!")
year = int(input('请输入年份：'))
month = int(input('请输入月份：'))
day = int(input('请输入日期: '))
run = [31,29,31,30,31,30,31,31,30,30,31,30]
ping = [31,28,31,30,31,30,31,31,30,30,31,30]
x = 0
if month > 12 or day > 31:
    print("输入错误！请核对后重新输入")
elif (year/4)*10%10==0 and (year/100)*10%10!=0 or (year/400)*10%10==0:
    for i in range(0,month-1):
        x += run[i]
else:
    for i in range(0,month-1):
        x += ping[i]
    print('这是第%d天.' % (x+day))