/*

NOTE:  This is an implemenation of the solution using segment trees.
So I made a 2D Segment Tree to answer the range queries.
Although this particular question can be solved using dp(prefix sums)
but I wanted to implement 2D segment trees thats why I went with approach to solve this
as this is a good trick which can be used to solve much more things on matrix involving range queries.
I can also perform updations in the matrix alos while mainting the time complexity while
updations in the dp solution will not be possible while maintaining the TC.

*/



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

struct point {
	ll x, y;
};

struct  Segtree2D {
	ll size;
	vector<vector<ll>> values;

	void init(ll n) {
		size = 1;
		while (size < n)	size *= 2;
		values = vector<vector<ll>>(2 * size, vector<ll>(2 * size, 0));
	}

	void build_y(vector<vector<ll>>& matrix, ll x, ll lx, ll y, ll ly, ll ry) {
		if (ry - ly == 1) {
			if (ly < (ll)matrix.size())
				values[x][y] = matrix[lx][ly];
			return;
		}

		ll my = ly + (ry - ly) / 2;
		build_y(matrix, x, lx, 2 * y + 1, ly, my);
		build_y(matrix, x, lx, 2 * y + 2, my, ry);
		values[x][y] = values[x][2 * y + 1] + values[x][2 * y + 2];
		return;
	}

	void build_x(vector<vector<ll>>& matrix, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			if (lx < (ll)matrix.size())
				build_y(matrix, x, lx, 0, 0, size);
			return;
		}

		ll mx = lx + (rx - lx) / 2;
		build_x(matrix, 2 * x + 1, lx, mx);
		build_x(matrix, 2 * x + 2, mx, rx);

		rep(i, 2 * size) {
			values[x][i] = values[2 * x + 1][i] + values[2 * x + 2][i];
		}

	}

	void build(vector<vector<ll>>& matrix) {
		build_x(matrix, 0, 0, size);
	}

	ll sum_y(point p1, point p2, ll x, ll lx, ll y, ll ly, ll ry) {
		if (ly >= p2.y || ry <= p1.y)	return 0;
		if (ly >= p1.y && ry <= p2.y )	return values[x][y];

		ll my = ly + (ry - ly) / 2;
		return sum_y(p1, p2, x, lx, 2 * y + 1, ly, my) + sum_y(p1, p2, x, lx, 2 * y + 2, my, ry);
	}

	ll sum_x(point p1, point p2, ll x , ll lx, ll rx) {
		if (lx >= p2.x || rx <= p1.x)	return 0;
		if (lx >= p1.x && rx <= p2.x )	return sum_y(p1, p2, x, lx, 0, 0, size);

		ll mx = lx + (rx - lx) / 2;
		return sum_x(p1, p2, 2 * x + 1, lx, mx) + sum_x(p1, p2, 2 * x + 2, mx, rx);
	}

	ll sum(point p1, point p2) {
		// cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
		return sum_x(p1, p2, 0, 0, size);
	}

	void printTree() {
		rep(i, 2 * size) {
			rep(j, 2 * size)
			cout << values[i][j] << " ";
			cout << endl;
		}
	}
};



void solve() {

	ll n, q;
	cin >> n >> q;

	vector<vector<ll>> matrix(n, vector<ll>(n));
	rep(i, n) {
		rep(j, n) {
			char x;
			cin >> x;

			if (x == '.') {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;
			}
		}
	}

	Segtree2D st;
	st.init(n);
	st.build(matrix);
	// st.printTree();


	while (q--) {
		point p1, p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;

		ll x1, x2, y1, y2;
		x1 = min(p1.x, p2.x);
		x2 = max(p1.x, p2.x);
		y1 = min(p1.y, p2.y);
		y2 = max(p1.y, p2.y);

		p1 = {x1 - 1, y1 - 1};
		p2 = {x2 , y2};

		cout << st.sum(p1, p2) << endl;
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