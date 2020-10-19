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
#define pb 							push_back
#define pob 						pop_back
#define pf 							push_front
#define pof 						pop_front
#define maxE(a,n) 					*max_element(a,a+n);
#define minE(a,n) 					*min_element(a,a+n);
#define all(x) 						x.begin(), x.end()

#define fast 						ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fori(i,a,n) 				for (ll  i=a;i<n;i++)
#define ford(i,a,n) 				for (ll  i=n-1;i>=a;i--)

ll gcd(ll a, ll b){ll temp;while (b > 0){temp = a%b;a = b;b = temp;} return a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll power(ll x, ll b,ll m) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= m;} b >>= 1; x *= x; x %= m;} return p % m;}
void dbg(string s){cout<<s<<endl;}

void solve(){

	ll x,y;
	cin>>x>>y;
	ll ans;
	if(x >= y){
		if(x&1){
			ans = (x-1)*(x-1) + y;
			cout<<ans<<endl;
			// cout<<"lmao"<<endl;
		}
		else{
			ans = x*x - y + 1;
			cout<<ans<<endl;
			// cout<<"lol"<<endl;
		}
	}
	else{
		if(y&1){
			ans = y*y - x + 1;
			cout<<ans<<endl;
			// cout<<"rofl"<<endl;
		}
		else{
			ans = (y-1)*(y-1) + x;
			cout<<ans<<endl;
			// cout<<"haha"<<endl; 
		}
	}
	
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("D:\\CODING\\CSES\\input.txt", "r", stdin);
	freopen("D:\\CODING\\CSES\\output.txt", "w", stdout);
	#endif

	fast;
	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}