#include<iostream>
using namespace  std;

void subset(int *a,int n){
	cout <<n<<endl;
	for(int i =0;i<(1<<n);i++){
		int s=0;
		cout << i <<endl;
		for (int j =0;j<n;j++){
			if (i&(1<<j)){
				s+= a[j];
			}
		}
		//x[i]=s;
	}
}
int main(){
	int  a[] = {3, 34, 4, 12, 5, 2};
    int n=6;
    int S = 10;
    subset(a,n);
    return 0;
}
