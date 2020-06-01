#include<bits/stdc++.h>

using namespace std;

#define fastio ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define foo(i,a,n) for(ll i = (a); i <= n; i++)
#define frr(i,a,n) for(ll i = (a); i >= n; i--)
#define fr(i,n) for(ll i = n-1; i >= 0; i--)
#define fo(i,n) for(ll i = 0; i < n; i++)
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define s second
#define f first

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
//typedef unordered_map<ll,ll> um;
typedef vector<pll> vpll;

const ll MOD=1e+9+7;
const ll MAXN=1e+5+7;
const ll INF=1e+18;

//<<-----Declare Variable Here------->>//
ll n,m;
ll res1, res2;
ll dp[MAXN][47]={};
//<<-----Implement Functions Here---->>//
ll add(ll a, ll b) {return (a+b)%MOD;}
ll mult(ll a, ll b) {return (a * b)%MOD;}
ll sub(ll a, ll b) {return (a-b+MOD)%MOD;}


ll fastexp(ll x, ll y){
	ll res=1;
	while(y){
		if(y&1){
			res=mult(res,x);
		}
		y/=2;
		x=mult(x,x);
	}
	return res;
}

ll solve(ll n, ll m){
	if(m==1)swap(n,m);
	if(m==1 && n==1){
		return 2;
	}

	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=1;
	ll res=0;
	for(int i=2;i<m-1;i+=2){

		dp[i][0]=add(add(dp[i-2][0],dp[i-2][1]),dp[i-2][3]);
		dp[i][1]=add(add(dp[i-2][0],dp[i-2][1]),dp[i-2][2]);
		dp[i][2]=add(dp[i-2][0],dp[i-2][3]);
		dp[i][3]=add(dp[i-2][1],dp[i-2][2]);

	}

	if(m&1){
		int i=m-1;
		res=add(res,add(add(mult(dp[i-2][0],2),mult(dp[i-2][1],2)),add(dp[i-2][2],dp[i-2][3])));
	}
	if(m&1 && n==1){
		res1=res;
	}
	else if(m%2!=0 && n!=1)res1=add(add(add(dp[m-1][0],dp[m-1][1]),add(dp[m-1][2],dp[m-1][3])),res)+2;
	else if(m%2==0 && n!=1){
		res=add(add(add(dp[m-2][0],dp[m-2][1]),add(dp[m-2][2],dp[m-2][3])),fastexp(2,m/2-1));
		if(m<=2)res1=res+1;
		else res1=res;
	}
	else res1=add(add(dp[m-2][0],dp[m-2][1]),add(dp[m-2][2],dp[m-2][3]));
	return res1;
}

//<<-----Start of Main--------------->>//

int main(){
	fastio;

	int t;
	cin >> t;
	while(t--)
	{
	    cin>>n>>m;
	if(m==1 && n==1){
		cout<<2<<endl;
		return 0;
	}
	if(m==1)swap(n,m);
	if(n==1 )cout<<solve(n,m)<<endl;
	else cout<<sub(add(solve(1,n),solve(1,m)),2)<<endl;
	}
}
