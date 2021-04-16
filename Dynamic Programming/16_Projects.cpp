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

struct project {
	ll sd, ed, reward;
};


bool comp(project &p1, project &p2) {
	if (p1.ed == p2.ed )
		return p1.sd < p2.sd;
	return p1.ed < p2.ed;
}

int find(vector<ll>& ep, ll m) {

	auto f = lower_bound(all(ep), m);
	if (f == ep.begin())
		return 0;
	else
		return distance(ep.begin(), f);

}

void solve() {

	ll n;
	cin >> n;

	vector<project> a(n);
	fori(i, 0, n)	cin >> a[i].sd >> a[i].ed >> a[i].reward;
	sort(all(a), comp);

	vector<ll> endpts;
	fori(i, 0, n)	endpts.pb(a[i].ed);

	vector<ll> dp(n + 1  , 0);
	dp[1] = a[0].reward;

	fori (i, 1, n ) {
		ll tr = a[i].reward;
		int pos = find(endpts, a[i].sd);
		dp[i + 1] = max(dp[i], tr + dp[pos]);
	}

	cout << dp[n] << endl;

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