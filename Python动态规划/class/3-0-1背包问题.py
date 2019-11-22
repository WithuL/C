import numpy as np
weight={}
weight["water"]=3
weight["book"]=1
weight["food"]=2
weight["jacket"]=2
weight["camera"]=1
worth={}
worth["water"]=10
worth["book"]=3
worth["food"]=9
worth["jacket"]=5
worth["camera"]=6
table_name={}
table_name[0]="water"
table_name[1]="book"
table_name[2]="food"
table_name[3]="jacket"
table_name[4]="camera"
table=np.zeros((len(weight),6))
table_class=np.zeros((len(weight),6),dtype=np.dtype((np.str_,500)))
for i in range(0,len(weight)):
    for j in range(0, 6):
        this_weight = weight[table_name[i]]
        this_worth = worth[table_name[i]]
        if i > 0:
            before_worth = table[i - 1, j]
            temp=0
            if(this_weight<=j):
                temp=table[i-1,j-this_weight]
            synthesize_worth=0
            if(this_weight-1<=j):
                synthesize_worth=this_worth+temp
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
            if(this_weight-1<=j):
                table[i,j]=this_worth
                table_class[i][j]=table_name[i]
print(table)
print("-----------------------------")
print(table_class)
