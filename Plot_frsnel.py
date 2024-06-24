import matplotlib.pyplot as plt
import scipy
import numpy as np

f1=open('FrS_100.txt','r')
f2=open('FrC_100.txt','r')

x=np.arange(0.0,10.0,0.1)
Sx, Cx=scipy.special.fresnel(x)
FrS=[]
for r in f1:
    FrS.append(float(r))

FrC=[]
for r in f2:
    FrC.append(float(r))

plt.plot(x,Sx,label='Python Fresnel Sin', alpha=0.4,ls='dotted')
plt.plot(x,FrS,label='PRESTO Fresnel Sin', alpha=0.4, ls='dashed')

plt.plot(x,Cx,label='Python Fresnel Cos', alpha=0.4,ls='dotted')
plt.plot(x,FrC,label='PRESTO Fresnel Cos', alpha=0.4, ls='dashed')


plt.legend()
plt.show()
