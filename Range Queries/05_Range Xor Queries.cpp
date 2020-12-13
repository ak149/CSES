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
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll power(ll x, ll b,ll m) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= m;} b >>= 1; x *= x; x %= m;} return p % m;}
void dbg(string s){cout<<s<<endl;}
 
 
struct segtree{
	vector<int> xors;
	int size;
 
	void init(int n){
		size = 1;
		while(size < n)	size*=2;
		xors.assign(2*size,0);
	}
 
	void build(vector<int>& a,int lx,int rx,int idx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				xors[idx] = a[lx];
			}
			return;
		}
 
		int mid = (lx + rx)/2;
		build(a,lx,mid,2*idx + 1);
		build(a,mid,rx,2*idx + 2);
 
		xors[idx] = xors[2*idx + 1] ^ xors[2*idx + 2];
		return;
	}
	
	void build(vector<int>& a){
		build(a,0,size,0);
	}
 
	int findxor(int l,int r,int lx, int rx,int idx){
		if(lx >= r || rx <= l)	return 0;
		if(lx >= l && rx <= r)	return xors[idx];
 
		int mid = (lx + rx)/2;
		int x1 = findxor(l,r,lx,mid,2*idx + 1);
		int x2 = findxor(l,r,mid,rx,2*idx + 2);
 
		return x1 ^ x2;
	}
 
	int findxor(int l ,int r){
		return findxor(l,r,0,size,0);
	}
 
	void print_tree(){
		trav(x,xors);
	}
};
 
 
int main(){
 
	// #ifndef ONLINE_JUDGE
	// freopen("D:\\CODING\\CSES\\input.txt", "r", stdin);
	// freopen("D:\\CODING\\CSES\\output.txt", "w", stdout);
	// #endif
 
	fast;
 
	int n,q;
	cin>>n>>q;
 
	vector<int> a(n);
	rep(i,n)	cin>>a[i];
 
	segtree st;
	st.init(n);
	st.build(a);
	// st.print_tree();
	while(q--){
		int l,r;
		cin>>l>>r;
 
		cout<<st.findxor(l - 1,r)<<endl;
	}
 
}


// #include<bits/stdc++.h>
// using namespace std;

// #define INF  						1e15
// #define EPS   						1e-9
// #define MOD 						1000000007
// #define Pi 							3.14159265358979323846264338327950288419716939937510

// #define umap 						unordered_map
// #define uset 						unordered_set
// #define fi 							first
// #define se 							second
// #define ll 							long long 
// #define vi 							vector<int>
// #define pii 						pair<int,int>
// #define vll 						vector<ll>
// #define pll							pair<ll,ll>
// #define vvll						vector<vector<ll>>
// #define pb 							push_back
// #define pob 						pop_back
// #define pf 							push_front
// #define pof 						pop_front
// #define maxE(a,n) 					*max_element(a,a+n);
// #define minE(a,n) 					*min_element(a,a+n);
// #define all(x) 						x.begin(), x.end()
// #define rev(x)						reverse(all(x))

// #define fast 						ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// #define rep(i,n)					for (ll  i=0;i<n;i++)
// #define repd(i,n)					for (ll  i = n-1;i>=0;i--)
// #define fori(i,a,n) 				for (ll  i=a;i<n;i++)
// #define ford(i,a,n) 				for (ll  i=n-1;i>=a;i--)
// #define trav(x,a)					for(auto x:a){cout<<x<<" ";}
	
// ll gcd(ll a, ll b){	return __gcd(a,b);}
// ll lcm(ll a, ll b){return a*b/gcd(a,b);}
// ll power(ll x, ll b,ll m) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= m;} b >>= 1; x *= x; x %= m;} return p % m;}
// void dbg(string s){cout<<s<<endl;}



// vector<ll> xors;
// ll size;

// void init(ll n){
// 	size = 4*n + 1;
// 	xors.assign(size,0LL);
// }

// void build(vector<ll> a,ll lx,ll rx,ll idx){
// 	if(lx == rx){
// 		xors[idx] = a[lx];		
// 		return;
// 	}

// 	ll mid = (lx + rx)/2;
// 	build(a,lx,mid,2*idx);
// 	build(a,mid + 1,rx,2*idx + 1);

// 	xors[idx] = xors[2*idx] ^ xors[2*idx + 1];
// 	return;
// }

// void build(vector<ll> a,ll n){
// 	build(a,0,n - 1,1);
// }

// ll findxor(ll l,ll r,ll lx, ll rx,ll idx){
// 	if(lx > r || rx < l)	return 0;
// 	if(lx >= l && rx <= r)	return xors[idx];

// 	ll mid = (lx + rx)/2;
// 	ll x1 = findxor(l,r,lx,mid,2*idx);
// 	ll x2 = findxor(l,r,mid + 1,rx,2*idx + 1);

// 	return x1 ^ x2;
// }

// ll findxor(ll l ,ll r,ll n){
// 	return findxor(l,r,0,n - 1,1);
// }



// int main(){

// 	#ifndef ONLINE_JUDGE
// 	freopen("D:\\CODING\\CSES\\input.txt", "r", stdin);
// 	freopen("D:\\CODING\\CSES\\output.txt", "w", stdout);
// 	#endif

// 	fast;

// 	ll n,q;
// 	cin>>n>>q;

// 	vector<ll> a(n);
// 	rep(i,n)	cin>>a[i];


// 	init(n);
// 	build(a,n);
// 	// st.print_tree();
// 	while(q--){
// 		int l,r;
// 		cin>>l>>r;
// 		cout<<findxor(l - 1,r - 1,n)<<endl;
// 	}

// }