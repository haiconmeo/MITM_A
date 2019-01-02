#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <stack>
#include <stdlib.h>
#define lowbit(x) (x&-x)
#define e exp(1.0)
//ios::sync_with_stdio(false);
//    auto start = clock();
//    cout << (clock() - start) / (double)CLOCKS_PER_SEC;
typedef long long ll;
typedef long long LL;
using namespace std;
const int maxn=1<<18;;
int n,m1,m2,sum,half,ans,cnt,a[100],b[100];
int vis[maxn];
void pre(int now,int s)
{
    if(now==m1)
    {
        vis[cnt++]=s;
        return ;
    }
    pre(now+1,s);
    pre(now+1,a[now]+s);
}
void dfs(int now,int s)
{
    if(now==m2)
    {
        int k=lower_bound(vis,vis+cnt,half-s)-vis;
        if(k<cnt)ans=min(ans,abs(sum-s-vis[k]-s-vis[k]));
        cout <<ans<<"  "<<s<<endl;
        return ;
    }
    dfs(now+1,s);
    dfs(now+1,b[now]+s);
}

int main(){

cin>>n;
        m1=n/2;m2=n-m1;
        sum=0;
        for(int i=0;i<m1;i++)cin>>a[i],sum+=a[i];
        //pre(0,0);
        //for(int i =0;i<cnt;i++) cout <<vis[i]<<endl;
        for(int i=0;i<m2;i++)cin>>b[i],sum+=b[i];;
		half=sum/2;cnt=0;ans=sum;
        pre(0,0);
        sort(vis,vis+cnt);
        dfs(0,0);
        //dfs(0,0);
}
