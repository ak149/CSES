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
#define trav(x,a)					for(auto x:a){cout<<x<<" ";}cout<<endl;
	
ll gcd(ll a, ll b){	return __gcd(a,b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll power(ll x, ll b,ll m) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= m;} b >>= 1; x *= x; x %= m;} return p % m;}
void dbg(string s){cout<<s<<endl;}
 
ll n,m;
vector<vector<pll>> g;
 
 
vector<ll> dijktras(ll src){
	vector<ll> distances(n + 1,LLONG_MAX);
	set<pair<ll,ll>> s;
 
	distances[src] = 0;
	s.insert({0,src});
 
	while(!s.empty()){
		auto p = *(s.begin());
		ll u = p.se;
		ll d = p.fi;
		s.erase(s.begin());
 
		for(auto nbr:g[u]){
			ll v = nbr.fi;
			ll wt = nbr.se;
 
			if(distances[u] != INT_MAX && distances[v] > distances[u] + wt){
				auto it =  s.find({distances[v],v});
				if(it != s.end()){
					s.erase(it);
				}
 
				distances[v] = distances[u] + wt;
				s.insert({distances[u] + wt,v});
			}
		}
	}
 
	return distances;
}
 
void solve(){
 
	cin>>n>>m;
 
	g = vector<vector<pll>>(n + 1);
 
	while(m--){
		ll u,v,weight;
		cin>>u>>v>>weight;
 
		g[u].pb({v,weight});
	}	
 
	ll src = 1;
	vector<ll> shortest_distance = dijktras(src);
	fori(i,1,n + 1)	cout<<shortest_distance[i]<<" \n"[i == n ];
 
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