from scipy import optimize
import numpy as np
c = np.array([0.75,0.7753,1.15,1.3611,1.9148,-0.375,-0.5,-0.4475,-1.2304,-0.35])
A = np.array([[5,0,10,0,0,0,0,0,0,0],[0,7,0,9,12,0,0,0,0,0],[0,0,0,0,0,6,8,0,0,0],[0,0,0,0,0,0,0,4,11,0],[0,0,0,0,0,0,0,0,0,7]])
b = np.array([6000,10000,4000,7000,4000])
Aeq = np.array([[1,1,0,0,0,-1,0,-1,0,-1],[0,0,1,1,0,0,-1,0,0,0],[0,0,0,0,1,0,0,0,-1,0]])
Beq = np.array([[0],[0],[0]])
res = optimize.linprog(-c,A,b,Aeq,Beq)
print(res)