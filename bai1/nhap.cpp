#include <iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz 1000005
using namespace std;
ll prime[sz],s[sz],k,a,b,cnt=0ll;
void sieve()
{
    for(ll i=0;i<sz;i++)
     s[i]=1,prime[i]=0;
    for(ll i=2;i<sz;i++)
    {
        if(!prime[i])
        {
            s[i]=i;   
            for(ll j=i*2;j<sz;j+=i)
             s[j]*=i,prime[j]=1;
        }
    }
}
int main(){
	sieve();
	//for(int i =0;i<10;i++) !prime[i]? cout<<i<<endl:cout<<endl;
	for (int i =0;i<100;i++) cout <<s[i]<<" ";
}
