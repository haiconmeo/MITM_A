#include <bits/stdc++.h> 
#include <fstream>
#include <ctime>

using namespace std; 
typedef long long int ll; 
ll *X = new ll[40000005];ll *Y = new ll[40000005]; 
// khoi tao 2 mang x y , de luu cai tong con 
ll S = 0;
void calcsubarray(ll a[], ll x[], int n, int c) 
{ 
// viec tim tong con dua tren  ki thuat Bitmask
// sau khi thuc hien cac mang se chua cac tong con tuong ung
    for (int i=0; i<(1<<n); i++) 
    { 
        ll s = 0; 
        for (int j=0; j<n; j++) 
            if (i & (1<<j)) 
                s += a[j+c]; 
        x[i] = s; 
    } 
} 
  

bool solveSubsetSum(ll a[], int n, ll S) 
{ 
    
    calcsubarray(a, X, n/2, 0); 
    calcsubarray(a, Y, n-n/2, n/2); 
  
    int size_X = 1<<(n/2); 
    int size_Y = 1<<(n-n/2); 
  
    // sap xep mang y theo thu tu tang dan thuan tien trong viec tim va so sanh kq
    sort(Y, Y+size_Y); 
  
    
    bool max = 0; 
  	if(S %2 ==1 || n %2 ==1) return 0;
   S/=2;
    for (int i=0; i<size_X; i++) 
    { 
    	
        if (X[i] <= S) 
        { 
            
            int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y; // tim can duoi cua s-x[i] trong y
  
           // neu s - x[i] ko thuoc y thi p --
            if (p == size_Y || Y[p] != (S-X[i])) 
                p--; 
  
            if ((Y[p]+X[i]) == S ) {
				max=1;
				break;
			}
                
                
        } 
    } 
    return max; 
} 
  
// Driver code 
int main() 
{ 
	int n;
	ll a[70];
	ofstream outfile;
    outfile.open("text9.in"); 	
  	cin >>n;
  	outfile<<n<<endl;
  	S=0;
	for (int i =0;i<n;i++){
		cin >>a[i];
		outfile<<a[i]<<" ";
		S+=a[i];
	}
	outfile.close();
	ofstream in;
    in.open("text9.out");
	string x=solveSubsetSum(a,n,S)?"Yes":"No";
	cout <<x<<endl; 
	in<<x<<endl;
	in.close();
  
	
       
           
    return 0; 
} 
