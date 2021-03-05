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
#define trav(x,a)					for(auto x:a){cout<<x<<" ";}

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

	ll n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n)	cin >> a[i];

	sort(all(a));
	ll max_sum = 1000 * n;
	vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1));
	fori(j, 1, max_sum + 1)
	dp[0][j] = false;
	rep(i, n + 1)
	dp[i][0] = true;

	fori(i, 1, n + 1) {
		fori(j, 1, max_sum + 1) {
			dp[i][j] = dp[i - 1][j];
			if (a[i - 1] <= j)
				dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
		}
	}

	vector<ll> posssums;
	fori(i, 1, max_sum + 1) {
		if (dp[n][i])
			posssums.pb(i);
	}

	cout << posssums.size() << endl;
	trav(x, posssums);


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