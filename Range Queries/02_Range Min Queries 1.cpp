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

// struct segtree{
// 	vector<ll> mins;
// 	ll size;

// 	void init(ll n){
// 		size = 4*n + 1;
// 		mins.assign(size,1e10);
// 	}

// 	void build(vector<ll> a,ll lx,ll rx,ll idx){
// 		if(lx == rx){
// 			mins[idx] = a[lx];
// 			return;
// 		}

// 		ll mid = (lx + rx)/2;
// 		build(a,lx,mid,2*idx);
// 		build(a,mid + 1,rx,2*idx + 1);

// 		mins[idx] = min(mins[2*idx],mins[2*idx + 1]);
// 		return;
// 	} 

// 	void build(vector<ll> a,ll n){
// 		build(a,0,n - 1,1);
// 	}

// 	ll query(ll l ,ll r , ll lx, ll rx ,ll idx){
// 		if(l > rx || r < lx)	return INT_MAX;
// 		if(lx >= l && rx <= r)	return mins[idx];

// 		ll mid = (lx + rx)/2;
// 		ll ls = query(l,r,lx,mid,2*idx);
// 		ll rs = query(l,r,mid + 1,rx,2*idx +1 );

// 		return min(ls,rs);
// 	}


// 	ll query(ll l,ll r,ll n){
// 		return query(l,r,0,n - 1,1);
// 	}

// 	void printtree(){
// 		trav(x,mins);
// 	}
	
// };




// int main(){

// 	#ifndef ONLINE_JUDGE
// 	freopen("D:\\CODING\\CSES\\input.txt", "r", stdin);
// 	freopen("D:\\CODING\\CSES\\output.txt", "w", stdout);
// 	#endif

// 	fast;

// 	ll n,q;
// 	cin>>n>>q;
// 	vector<ll> a(n);
// 	rep(i,n) 	cin>>a[i];

// 	segtree st;
// 	st.init(n);
// 	st.build(a,n);

// 	while(q--){
// 		ll l,r;
// 		cin>>l>>r;
// 		l--;
// 		r--;
// 		cout<<st.query(l,r,n)<<endl;
// 	}

// }
#include<bits/stdc++.h>
#define COUNT 5
using namespace std;

struct segtree{
	int size;
	vector<int> mins;

	void init(int n){
		size = 1;
		while(size < n)	size*=2;
		mins.assign(2*size,INT_MAX);
	}	

	void build(vector<int>& a,int x,int lx,int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				mins[x] = a[lx];
			}
			return;
		}

		int m = (lx + rx)/2;
		build(a,2*x + 1,lx,m);
		build(a,2*x + 2,m,rx);

		mins[x] = min(mins[2*x + 1],mins[2*x + 2]);
	}

	void build(vector<int>& a){
		build(a,0,0,size);
	}

	void set(int i,int v,int x,int lx,int rx){
		if(rx - lx == 1){
			mins[x] = v;
			return;
		}

		int mid = (lx + rx)/2;

		if( i < mid){
			set(i,v,2*x + 1,lx,mid);
		}
		else{
			set(i,v,2*x + 2,mid,rx);
		}

		mins[x] = min(mins[2*x +1],mins[2*x + 2]);

		return;
	}


	void set(int i,int v){
		set(i,v,0,0,size);
	}


	int findMin(int l,int r,int x,int lx,int rx){
		if(lx >= r || l >= rx)	return INT_MAX;
		if(lx >= l && rx <= r)	return mins[x];

		int mid = (lx + rx)/2;

		int m1 = findMin(l,r,2*x + 1,lx,mid);
		int m2 = findMin(l,r,2*x + 2,mid,rx);

		return min(m1,m2);
	}


	int findMin(int l,int r){
		return findMin(l,r,0,0,size);
	}


	// void print2D(vector<int>& mins,int idx,int space){    
	//     if (idx >= mins.size())  
	//         return;  
	//     space += COUNT;  
	  
	//     print2D(mins,2*idx+2, space);  
	//     cout<<endl;  
	//     for (int i = COUNT; i < space; i++)  
	//         cout<<" ";  
	//     cout<<mins[idx];  
	//     print2D(mins,2*idx+1, space);  
	// } 
	
	void printTree(){
		// print2D(mins,0,0);
		for(auto m:mins){
			cout<<m<<" ";
		}
	}
};


int main(){

	#ifndef ONLINE_JUDGE
	freopen("D:\\CODING\\CSES\\input.txt", "r", stdin);
	freopen("D:\\CODING\\CSES\\output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;

	segtree sg;
	sg.init(n);

	vector<int> a(n);
	for(int i=0;i<n;i++)	cin>>a[i];

	sg.build(a);

	while(m--){
		int l,r;
		cin>>l>>r;
		l--;
		cout<<sg.findMin(l,r)<<endl;
	}

	// sg.printTree();

}