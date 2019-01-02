#include <bits/stdc++.h> 
#include <fstream>
#include <ctime>

using namespace std; 
typedef long long int ll; 
ll *X = new ll[40000005];ll *Y = new ll[40000005]; 
// khoi tao 2 mang x y , de luu cai tong con 
void tinhsubset(ll a[], ll x[], int n, int c) 
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
      //  cout <<x[i]<<endl;
    } 
} 
  

ll thuchien(ll a[], int n, ll S) 
{ 
    
    tinhsubset(a, X, n/2, 0); 
    //cout <<"cak"<<endl;
    tinhsubset(a, Y, n-n/2, n/2); 
  	
    int size_X = 1<<(n/2); 
    int size_Y = 1<<(n-n/2); 
  
    // sap xep mang y theo thu tu tang dan thuan tien trong viec tim va so sanh kq
    sort(Y, Y+size_Y); 
  
    
    ll dem = 0; 
  
   
    for (int i=0; i<size_X; i++) 
    { 
    	
        if (X[i] <= S) 
        { 
            
            for(int p =0;p<size_Y;p++){
				if(X[i]+Y[p]<=S){
					dem++;
				}
			}
        } 
    } 
    return dem; 
} 
  
// Driver code 
int main() 
{ 
	int n =34;
	ll a[70];
	ll S = 200000;
	ofstream outfile;
   outfile.open("text10.in");
   outfile << n<<endl;
    outfile << S<<endl;
/*std::ifstream f("text.dat");
 	int n;
 	int S;
 	f >>n;
 	f>>S;*/
  srand(time(NULL));

	for (int i =0;i<n;i++){
		a[i] = rand() %1000*99;
			outfile<<a[i]<<endl;
	}
    outfile.close();
   
     outfile.open("text10.out");
     outfile << thuchien(a,n,S);
    printf("Largest value smaller than or equal to given "
           "sum is %lld\n", thuchien(a,n,S)); 
       outfile.close();    
           
    return 0; 
} 
