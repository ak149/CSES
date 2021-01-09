#include<bits/stdc++.h>
using namespace std;

#define INF  						1e15
#define EPS   						1e-9
#define MOD 						1000000007
#define Pi 							3.14159265358979323846264338327950288419716939937510

#define umap 						unordered_map
#define uset 						unordered_set
#define fi 							first
#define se 							second
#define ll 							long long 
#define vi 							vector<int>
#define pii 						pair<int,int>
#define vll 						vector<ll>
#define pll							pair<ll,ll>
#define vvll						vector<vector<ll>>
#define pb 							push_back
#define pob 						pop_back
#define pf 							push_front
#define pof 						pop_front
#define maxE(a,n) 					*max_element(a,a+n);
#define minE(a,n) 					*min_element(a,a+n);
#define all(x) 						x.begin(), x.end()
#define rev(x)						reverse(all(x))

#define fast 						ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define rep(i,n)					for (ll  i=0;i<n;i++)
#define repd(i,n)					for (ll  i = n-1;i>=0;i--)
#define fori(i,a,n) 				for (ll  i=a;i<n;i++)
#define ford(i,a,n) 				for (ll  i=n-1;i>=a;i--)
#define trav(x,a)					for(auto x:a){cout<<x<<" ";}
	
ll gcd(ll a, ll b){	return __gcd(a,b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll power(ll x, ll b,ll m) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= m;} b >>= 1; x *= x; x %= m;} return p % m;}
void dbg(string s){cout<<s<<endl;}

ll n;
vector<vector<ll>> g;
vector<bool> visited;
umap<ll,pll> dp;

pll dfs(ll src,ll par){

	if(dp.find(src) != dp.end())
		return dp[src];

	// cout<<src<<" "<<par<<endl;
	pll curnode = {1,0};

	for(ll i = 0 ;i < g[src].size();i++){
		if(g[src][i] == par)
			continue;
		pll left = dfs(g[src][i],src);
		pll right = {0,0};
		for(ll j = i + 1 ; j < g[src].size();j++){
			if(g[src][j] == par)
				continue;
			right = dfs(g[src][j],src);

			curnode.fi = max(curnode.fi,1 + max(left.fi,right.fi));
			curnode.se = max({curnode.se,left.se,right.se,left.fi + right.fi});
		}
		curnode.fi = max(curnode.fi,1 + max(left.fi,right.fi));
		curnode.se = max({curnode.se,left.se,right.se,left.fi + right.fi});
	}
	
	return dp[src] = curnode;
}

void solve(){

	cin>>n;
	g = vector<vector<ll>>(n + 1);
	visited = vector<bool>(n + 1,false);
	dp.clear();

	rep(i,n - 1){
		ll u,v;
		cin>>u>>v;

		g[u].pb(v);
		g[v].pb(u);
	}

	pll ans = dfs(1,0);
	cout<<ans.se<<endl;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	fast;
	ll t = 1;

	while(t--){
		solve();
	}
}