#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define MAX 1000010

ll _sieve_size;
vector<ll> primes;
vector<bool> marked;

void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  marked.assign(MAX,1);
  marked[0] = marked[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (marked[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) marked[j] = 0;
    primes.push_back((int)i);
} }



int main()
{
    ll a,b;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        primes.clear();
        marked.clear();
    ll start,p;
    int root=sqrt(b)+1;
    sieve(root);
    marked.assign(MAX,1);
    int len=primes.size();
    if(a==1) marked[0]=0;
    for(int i=0;primes[i]*primes[i]<=b && i<len;i++)
    {
        p=primes[i];
        if(a%p!=0)
        start=a+(p-(a%p));
        else if(a%p==0)
            start=a;
        if(start==p) start+=p;
        for(ll j=start;j<=b;j+=p)
            marked[j-a]=0;//cout<<j-a<<" -> "<<marked[j-a]<<endl;
    }
    primes.clear();
    ll i=0,cnt=0;
    while((i+a)<=b){
        if(marked[i]==1)
            primes.push_back(i+a),cnt++;
    i++;
    }
    if(cnt<2) {printf("There are no adjacent primes.\n");continue;}
    ll mx,mn,dis,lo1,lo2,hi1,hi2,len2;
    len2=primes.size();
    for(int i=1;i<len2;i++)
    {
        if(i==1) {dis=primes[i]-primes[i-1];mx=mn=dis;hi1=hi2=1;lo1=lo2=0;}
        dis=primes[i]-primes[i-1];
        if(dis>mx){
            mx=dis; lo1=i-1; hi1=i;
            }
        if(dis<mn){
            mn=dis; lo2=i-1; hi2=i;
            }
    }
    printf("%lld,%lld are closest, %lld,%lld are most distant.\n",primes[lo2],primes[hi2],primes[lo1],primes[hi1]);
    }

    return 0;
}
