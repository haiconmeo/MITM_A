def _sum(A):
  f= open("test1.out","w")  
  sums = {}  
  for a in A:  
    for b in A:  
      sums[a + b] = (a, b)  
  
  for c in A:  
    for d in A:  
      if -(c + d) in sums:  
        B=sums[-(c + d)][0], sums[-(c + d)][1], c, d
        for item in B:
            f.write("%s\n" % item)
        return  
  
  f.write( "No solution.")
  f.close()
#f= open("test1.in","w")

A=[1,2,3,4,5,-6]
with open('test1.in', 'w') as f:
    for item in A:
        f.write("%s\n" % item)
f.close()        
        
_sum(A)
  
