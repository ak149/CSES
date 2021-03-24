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


struct Segtree {
	ll size;
	vector<ll> ops, values;

	void init(ll n) {
		size = 1;
		while (size < n)	size *= 2;
		ops = values = vector<ll>(2 * size, 0);
	}

	void build(vector<ll>& a, ll x, ll lx , ll rx) {
		if (rx - lx == 1) {
			if (lx < (ll)a.size())
				ops[x] = a[lx];
			return;
		}

		ll mx = lx + (rx - lx) / 2;
		build(a, 2 * x + 1, lx, mx);
		build(a, 2 * x + 2, mx, rx);
	}

	void build(vector<ll>&a) {
		build(a, 0, 0, size);
	}

	void modify(ll l, ll r, ll v, ll x, ll lx, ll rx) {
		if (lx >= r || rx <= l)	return;
		if (lx >= l && rx <= r) {
			ops[x] += v;
			return;
		}

		ll mx = lx + (rx - lx) / 2;
		modify(l, r, v, 2 * x + 1, lx, mx);
		modify(l, r, v, 2 * x + 2, mx, rx);
	}

	void modify(ll l, ll r, ll v) {
		modify(l, r, v, 0, 0, size);
	}

	ll get(ll i, ll x, ll lx, ll rx) {
		if (rx - lx == 1)
			return ops[x];

		ll mx = lx + (rx - lx) / 2;
		if (i < mx ) {
			return ops[x] + get(i, 2 * x + 1, lx, mx);
		}
		else {
			return ops[x] + get(i, 2 * x + 2, mx, rx);
		}
	}

	ll get(ll i) {
		return get(i, 0, 0, size);
	}

};


void solve() {

	ll n, q;
	cin >> n >> q;

	vector<ll> a(n);
	rep(i, n)	cin >> a[i];

	Segtree st;
	st.init(n);
	st.build(a);


	while (q--) {
		ll op;
		cin >> op;

		if (op == 1) {
			ll l, r, v;
			cin >> l >> r >> v;
			l--;
			// r--;
			st.modify(l, r, v);
		}
		else {
			ll i;
			cin >> i;
			i--;
			cout << st.get(i) << endl;
		}
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