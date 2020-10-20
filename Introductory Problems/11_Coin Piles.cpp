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

	ll a,b;
	cin>>a>>b;

	ll x = max(a,b);
	ll y = min(a,b);
	
	if(2*y < x){
		cout<<"NO"<<endl;
		return;
	}

	if(2*y == x){
		cout<<"YES"<<endl;
		return;
	}

	x = x % 3;
	y = y % 3;

	if(x == 0 && y == 0){
		cout<<"YES"<<endl;
	}
	else if(x == 1 && y == 2){
		cout<<"YES"<<endl;
	}
	else if(x == 2 && y == 1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

return;

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