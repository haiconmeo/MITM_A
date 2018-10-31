
// A recursive solution for subset sum problem 
#include <stdio.h> 
#include<iostream>
#include <cstdlib>
#include <fstream>

// Returns true if there is a subset of set[] with sun equal to given sum 
using namespace std;
typedef long long int ll; 

bool isSubsetSum(int set[], int n, int sum) 
{ 
   // Base Cases 
   if (sum == 0) 
     return true; 
   if (n == 0 && sum != 0) 
     return false; 
  
   // If last element is greater than sum, then ignore it 
   if (set[n-1] > sum) 
     return isSubsetSum(set, n-1, sum); 
  
   /* else, check if sum can be obtained by any of the following 
      (a) including the last element 
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) ||  
                        isSubsetSum(set, n-1, sum-set[n-1]); 
} 
  
int  calcsubarray(int a[], int n, int tong) 
{ 
	int max= -1000;
    for (int i=0; i<(1<<n); i++) 
    { 
        int s = 0; 
        for (int j=0; j<n; j++) 
            if (i & (1<<j)) {
            	 s += a[j];
            	 if (s>max && s<=tong){
            	 	max =s;
				 }
			}
               
				 
         
    }
	return max;  
} 
int main() 
{ 
std::ifstream f("text3.dat");
 	int n;
 	int sum;
 	f >>n;
 	f>>sum;
 	int set[50];
 	for(int i =0 ;i<n;i++){
 		f>>set[i];
	 }
  
   
  
  
     cout <<calcsubarray(set,n,sum); 
  
} 
