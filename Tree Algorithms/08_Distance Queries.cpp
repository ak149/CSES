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

vector<vector<ll>> g;
vector<ll> depth;
vector<vector<ll>> parents;
ll n,m,Q;

void build_table(ll src,ll parent){
	parents[0][src] = parent;
	for(ll p = 1 ; p < m ; p++){
		parents[p][src] = parents[p - 1][parents[p - 1][src]]; 
	}

	for(auto nbr:g[src]){
		if(nbr != parent){
			depth[nbr] = depth[src] + 1;
			build_table(nbr,src);
		}
	}

	return;
}


ll lca_binarylifting(ll u,ll v){
	if(u == v)
		return u;

	if(depth[u] < depth[v])	swap(u,v);

	ll len = depth[u] - depth[v];
	// if(len == 0)
	// 	return parents[0][u];
	for(ll i = m - 1; i >= 0 ; i--){
		if( (len >> i) & 1LL){
			u = parents[i][u];
		}
	}

	if(u == v)	return u;

	for(ll i = m - 1; i >= 0; i--){
		if(parents[i][u] != parents[i][v]){
			u = parents[i][u];
			v = parents[i][v];
		}
	}


	return parents[0][u];
}

void solve(){

	cin>>n>>Q;

	m = log2(n) + 1;
	g = vector<vector<ll>>(n + 1);
	parents = vector<vector<ll>>(m,vector<ll>(n + 1,0));
	depth = vector<ll>(n + 1,0);

	rep(i,n - 1){
		ll u,v;
		cin>>u>>v;

		g[u].pb(v);
		g[v].pb(u);
	}

	build_table(1,0);

	while(Q--){
		ll u,v;
		cin>>u>>v;

		ll lca = lca_binarylifting(u,v);
		
		/*
		Remember Higher the node in the tree lesser is its depth value.
		Therefore the subtractions are made accordingly so that we get a +ve answer.
		Else one could always use use abs() function. 
		*/

		if(lca == u){
			cout<<depth[v] - depth[u]<<endl;
		}
		else if(lca == v){
			cout<<depth[u] - depth[v]<<endl;
		}
		else{
			cout<<depth[u] + depth[v] - 2*depth[lca]<<endl;
		}
	}
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

