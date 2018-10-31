#include<iostream>
using namespace std;
int a[4][4];
int b[4][4];
int m[4][4];
int con[4][4];
bool in_con(int c){
	for (int i =0;i<4;i++){
		for (int j =0;j<4;j++){
			if (con[i][j]==c){
				return false;
			}
		}
	}
	return true;
}
void nhap(int a[4][4]){
	cout <<"dm nhap can than vao"<<endl;
	for (int i =0;i<4;i++){
		for(int j =0;j<4;j++){
		cout <<"a["<<i<<"]["<<j<<"]";
		cin >>a[i][j];
	}
}}

void out(int a[4][4]){
	for (int i =0;i<4;i++){
		for(int j =0;j<4;j++){
			cout <<a[i][j]<<"  ";
		}
		cout <<endl;
	}
	
}

void tron(){
	for (int i =0;i<4;i++){
		for (int j;j<4;j++ ){
			con[i][j]=-1;
		}
	}
	for (int i =0;i<4;i++){
		for(int j =0;j<4;j++){
			bool co =0;
			if(m[i][j]==0){// lay a
			
				for(int k=0;k<4;k++){
					for(int l=0;l<4;l++){
						if((a[k][l]!=-1)&& in_con(a[k][l])){
							con[i][j]=a[k][l];
							co =1;
							a[k][l]=-1;
							break;
						}
					}
					if(co) break;
				}
			}
			else{
				for(int k=0;k<4;k++){
					for(int l=0;l<4;l++){
						if((b[k][l]!=-1)&& in_con(b[k][l])){
							con[i][j]=b[k][l];
							co=1;
							b[k][l]=-1;
							break;
						}
					}
					if(co) break;
				}
			}
		}
	}
	out(con);
}
int main(){
	nhap(a);
	nhap(b);
	nhap(m);
	tron();
	
}
