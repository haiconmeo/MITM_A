import numpy as np
import random

def _sum(A):
  f= open("test10.out","w")
  dem=0
  sums = {}  
  for a in A:  
    for b in A:  
      sums[a + b] = (a, b)  
  
  for c in A:  
    for d in A:  
      if -(c + d) in sums:
          dem=dem+1
        
  print dem
  f.write("%s\n" % dem)
  f.close()
#f= open("test1.in","w")

A=np.random.randint(-100000, 100000, size=1000)
with open('test10.in', 'w') as f:
    for item in A:
        f.write("%s\n" % item)
f.close()        
        
_sum(A)
  
