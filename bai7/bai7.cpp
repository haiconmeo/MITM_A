#include <iostream>
#include<algorithm>
#include <fstream>
#include <ctime>
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
void gen(ll n,vector<ll> v[],ll A[])
{
     for(ll i=1;i<(1<<n);i++)
        {
            ll c=0,sum=0;
            for(ll j=0;j<n;j++)
            {
                if((i&(1<<j)))
                {
                    c++;
                    sum+=s[A[j]];
                }
            }
            if(sum<=b&&c<=k)
             v[c].pb(sum);
            if(sum<=b&&sum>=a&&c<=k)
             cnt++;
        }
}
int main()
{
    sieve();
    ll t,A[20],B[20],N;
    ll n=34;
    ll k=10;
    ll a=500;
    ll b=600;
       // cin>>n>>k>>a>>b;
    ofstream outfile;
   	outfile.open("text10.in");
   	outfile << n<<endl;
   	outfile << k<<endl;
   	outfile << a<<endl;
   	outfile << b<<endl;
        vector<ll> v2[40];
        vector<pair<ll,ll> > v1;
        for(ll i=0;i<n/2;i++){
			A[i] = rand() %100*99;
			outfile<<A[i]<<endl;
		}
        //  cin>>A[i];
        for(ll i=0;i<n-n/2;i++){
			B[i] = rand() %100*99;
			outfile<<B[i]<<endl;
		}
          //cin>>B[i];
          outfile.close();
        N=n/2;
        for(ll i=1;i<(1<<N);i++)
        {
            ll c=0,sum=0;
            for(ll j=0;j<N;j++)
            {
                if((i&(1<<j)))
                {
                    c++;
                    sum+=s[A[j]];
                }
            }
            if(sum<=b&&c<=k)
             v1.pb(mp(sum,c));
            if(sum<=b&&sum>=a&&c<=k)
             cnt++;
        }
        
        
        N=n-n/2;
        for(ll i=1;i<(1<<N);i++)
        {
            ll c=0,sum=0;
            for(ll j=0;j<N;j++)
            {
                if((i&(1<<j)))
                {
                    c++;
                    sum+=s[B[j]];
                }
            }
            if(sum<=b&&c<=k)
             v2[c].pb(sum);
            if(sum<=b&&sum>=a&&c<=k)
             cnt++;
        }
        
        ll ans=cnt;
        for(ll i=0;i<=k;i++)
         sort(v2[i].begin(),v2[i].end());
        for(ll i=0;i<v1.size();i++)
        {
            ll t1=v1[i].first;
            ll t2=v1[i].second;
            t2=k-t2;
            for(ll j=1;j<=t2;j++)
            {
                vector<ll> ::iterator it1=lower_bound(v2[j].begin(),v2[j].end(),a-t1);
                vector<ll> :: iterator it2=upper_bound(v2[j].begin(),v2[j].end(),b-t1);
                ans+=(it2-it1);
            }
        }
        outfile.open("text10.out");
        outfile<<ans<<endl;
        cout<<ans<<endl;
        outfile.close();
    return 0;
}
