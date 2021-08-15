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

void solve() {

	string s; cin >> s;
	ll n = s.size();
	ll dp[n][2] = {0};
	ll x1 = 0, y1 = -1;
	ll x2 = 0, y2 = -1;
	ll mx = 0, ans = 0;
	for (ll i = 0; i < n; i++) {
		ll k = 0;
		if (i > y1) k = 1;
		else k = min(dp[x1 + y1 - i][0], y1 - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
		dp[i][0] = k--;
		if (i + k > y1) x1 = i - k, y1 = i + k;
		if (2 * dp[i][0] - 1 > mx) ans = i - k, mx = 2 * dp[i][0] - 1;
		k = 0;
		if (i <= y2) k = min(dp[x2 + y2 - i + 1][1], y2 - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
		dp[i][1] = k--;
		if (i + k > y2) x2 = i - k - 1, y2 = i + k;
		if (2 * dp[i][1] > mx) ans = i - k - 1, mx = 2 * dp[i][1];
	}
	cout << s.substr(ans, mx);

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