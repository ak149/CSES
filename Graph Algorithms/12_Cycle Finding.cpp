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
#define endl						"\n"

#define fast 						ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define rep(i,n)					for (ll  i=0;i<n;i++)
#define repd(i,n)					for (ll  i = n-1;i>=0;i--)
#define fori(i,a,n) 				for (ll  i=a;i<n;i++)
#define ford(i,a,n) 				for (ll  i=n-1;i>=a;i--)
#define trav(x,a)					for(auto x:a){cout<<x<<" ";}cout<<endl;

ll gcd(ll a, ll b) {	return __gcd(a, b);}
ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}
ll power(ll x, ll b, ll m) {ll p = 1; while (b > 0) {if (b & 1) {p = p * x; p %= m;} b >>= 1; x *= x; x %= m;} return p % m;}
void dbg(string s) {cout << s << endl;}


/*PBDS*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

// pbds.find_by_order(k) (return iterator to kth largest element(from 0))
// pbds.order_of_key(k) (return number of elements in set which are strictly less than k)

struct Edges {
	ll u, v, d;
};

void solve() {

	ll v, e;
	cin >> v >> e;

	vector<Edges> g;
	rep(i, e) {
		ll u, v, d;
		cin >> u >> v >> d;

		g.pb({u - 1, v - 1, d});
	}


	vector<ll> dist(v, INF);
	vector<ll> parent(v, -1);
	dist[0] = 0;
	ll x;
	rep(i, v ) {
		x = -1;
		for (auto e : g) {
			if (dist[e.u] + e.d < dist[e.v]) {
				dist[e.v] = dist[e.u] + e.d;
				parent[e.v] = e.u;
				x = e.v;
			}
		}
	}
	// trav(x, dist);
	if (x == -1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		ll y = x;
		for (ll i = 0; i < v; ++i)
			y = parent[y];

		vector<ll> path;
		for (ll cur = y; ; cur = parent[cur]) {
			path.push_back (cur);
			if (cur == y && path.size() > 1)
				break;
		}
		reverse (path.begin(), path.end());

		for (ll i = 0; i < path.size(); ++i)
			cout << path[i] + 1 << ' ';

	}

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;
	ll t = 1;

	while (t--) {
		solve();
	}
}