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

vector<vector<ll>> g;
vector<ll> parents;
ll n,m;

bool bfs(ll src,ll sink){
	queue<ll> pending;
	vector<bool> visited(n,false);

	pending.push(src);
	visited[src] = true;

	while(!pending.empty()){
		ll u = pending.front();
		pending.pop();
		for(auto nbr:g[u]){
			if(visited[nbr] != true){
				pending.push(nbr);
				visited[nbr] = true;
				parents[nbr] = u;

				if(nbr == sink)
					return true;
			}
		}
	}

	return false;
}

void solve(){

	cin>>n>>m;

	g = vector<vector<ll>>(n);
	while(m--){
		ll sv,ev;
		cin>>sv>>ev;
		sv--;
		ev--;

		g[sv].pb(ev);
		g[ev].pb(sv);
	}
	parents = vector<ll>(n,-1);
	ll src = 0;
	ll sink = n - 1;
	bool canreach = bfs(src,sink);
	if(canreach){
		
		vector<ll> curpath;
		ll v = sink;
		while(v != src){
			curpath.pb(v + 1);
			v = parents[v];
		}
		curpath.pb(v + 1);
		reverse(all(curpath));
		cout<<curpath.size()<<endl;
		trav(x,curpath);
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
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