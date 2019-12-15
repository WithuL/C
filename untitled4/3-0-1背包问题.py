import numpy as np
#定义重量
weight={}
weight["water"]=3
weight["book"]=1
weight["food"]=2
weight["jacket"]=2
weight["camera"]=1
#定义价值
worth={}
worth["water"]=10
worth["book"]=3
worth["food"]=9
worth["jacket"]=5
worth["camera"]=6
#存放对应的物品名
table_name={}
table_name[0]="water"
table_name[1]="book"
table_name[2]="food"
table_name[3]="jacket"
table_name[4]="camera"
#创建矩阵，用来保存价值表
table=np.zeros((len(weight),6))
#创建矩阵，用来保存矩阵中的函数是如何得到的（物品名）
table_class=np.zeros((len(weight),6),dtype=np.dtype((np.str_,500)))
for i in range(0,len(weight)):
    for j in range(0, 6):
        # 获得重量
        this_weight = weight[table_name[i]]#让此时的重量等于i行物品的重量
        # 获得价值
        this_worth = worth[table_name[i]]#让此时的价值等于i行物品的价值
        if i > 0:
            before_worth = table[i - 1, j]#定义上一行同列的价值
            #获取（i-1，j-重量）
            temp=0
            if(this_weight<=j):
                temp=table[i-1,j-this_weight]
            #temp=table[i-1,j-this_weight]当前商品的价值
            #判断this worth能不能用，既重量有没有超标，如果重量超标则不能相加
            synthesize_worth=0
            if(this_weight-1<=j):
                synthesize_worth=this_worth+temp
            #与上一个单元格比较，选取大的
            if(synthesize_worth>before_worth):
                table[i,j]=synthesize_worth
                if (temp==0):
                    table_class[i][j]=table_name[i]
                else:
                    table_class[i][j]=table_name[i]+","+table_class[i-1][j-this_weight]
            else:
                table[i,j]=before_worth
                table_class[i][j]=table_class[i-1][j]
        else:
            if(this_weight-1<=j):#如果第i行的物品重量-1<j行重量，则令table的第i行j列元素等于i行物品的价值
                table[i,j]=this_worth
                table_class[i][j]=table_name[i]#让i行j列的物品等于i行的名字
print(table)
print("-----------------------------")
print(table_class)
