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

ll n,m,Q;
vector<vector<ll>> g,parents;
vector<ll> depth;


void build_table(ll src,ll par){
	parents[0][src] = par;
	for(ll p = 1;p < m ; p++){
		parents[p][src] = parents[p - 1][parents[p - 1][src]];
	}

	for(auto nbr:g[src]){
		if(nbr!= par){
			depth[nbr] = depth[src] + 1;
			build_table(nbr,src);
		}
	}
}

ll find_parent(ll u,ll p){
	for(ll i = m - 1; i >= 0 ;i--){
		if( ( p >> i) & 1){
			u = parents[i][u];
		}
	}

	return u;
}

void solve(){

	cin>>n>>Q;

	m = log2(n) + 1;

	g = vector<vector<ll>>(n + 1);
	parents = vector<vector<ll>>(m,vector<ll>(n + 1,0));
	depth = vector<ll>(n + 1,0);

	for(ll v = 2; v <= n ;v++){
		ll u;
		cin>>u;

		g[u].pb(v);
		g[v].pb(u);
	}

	build_table(1,0);
	
	while(Q--){
		ll u,p;
		cin>>u>>p;

		ll par = find_parent(u,p);
		if(par == 0){
			cout<<-1<<endl;
		}
		else{
			cout<<par<<endl;
		}
	}

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("D:\\CODING\\CSES\\input.txt", "r", stdin);
	freopen("D:\\CODING\\CSES\\output.txt", "w", stdout);
	#endif

	fast;
	ll t = 1;

	while(t--){
		solve();
	}
}