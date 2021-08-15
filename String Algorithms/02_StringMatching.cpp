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

// O(n^3)
// vector<ll> compute_lps_trivial(string s) {
// 	ll n = s.size();
// 	vector<ll> lps(n, 0);
// 	rep(i, n) {
// 		rep(length, i + 1) {
// 			if (s.substr(0, length) == s.substr(i - length + 1, length))
// 				lps[i] = length;
// 		}
// 	}

// 	return lps;
// }

vector<ll> compute_lps(string s) {
	ll n = s.size();
	vector<ll> lps(n, 0);

	ll i = 0, j;

	for (i = 1; i < n; i++) {
		j = lps[i - 1];
		while (j > 0 && s[i] != s[j])
			j = lps[j - 1];
		if (s[i] == s[j])
			j++;
		lps[i] = j;
	}

	return lps;
}


void solve() {

	string s, t;
	cin >> s >> t;

	string f = t + "$" + s;
	// cout << f << endl;
	vector<ll> lps = compute_lps(f);
	// rep(i, f.size()) {
	// 	cout << i + 1 << " ";
	// }
	// cout << endl;
	// for (auto x : f) {
	// 	cout << x << " ";
	// }
	// cout << endl;
	// for (auto d : lps) {
	// 	cout << d << " ";
	// }
	// cout << endl;

	vector<ll> occurences;
	for (ll i = t.size() + 1; i < (ll)f.size(); i++) {
		if (lps[i] == t.size()) {
			occurences.pb( (i - t.size()) - t.size() + 1);
		}
	}


	cout << occurences.size() << endl;



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