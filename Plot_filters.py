import matplotlib.pyplot as plt
import scipy
import numpy as np

f1=open('Filter_30.txt','r')
q=[]
real=[]
imag=[]
for line in f1:
    s=[float(r) for r in line.split()]
    q.append(s[0])
    real.append(s[1])
    imag.append(s[2])
real=np.array(real)
imag=np.array(imag)
ampl=np.abs(real + 1j*imag)
phase=np.angle(real + 1j*imag)


plt.plot(q,ampl,label='Filter amplitude (width 30 bins)')

#plt.plot(q,phase,label='Python Fresnel Cos', alpha=0.4,ls='dotted')


plt.legend()
plt.savefig('Filter_30_amp.png')
plt.clf()
plt.plot(q,phase,label='Filter phase (width 30 bins)')
plt.legend()
plt.savefig('Filter_30_phase.png')

