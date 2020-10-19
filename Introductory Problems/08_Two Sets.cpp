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

	ll n;
	cin>>n;

	ll sum = (n*(n + 1))/2;
	if(sum&1){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		vector<ll> v1,v2;
		if(n%4){
			v1.pb(1);
			v1.pb(2);
			v2.pb(3);
		}
		else{
			v1.pb(1);
			v1.pb(4);
			v2.pb(2);
			v2.pb(3);
		}

		ll j;
		if(n%4)
			j = 3;
		else 
			j = 4;
		fori(i,0,(n-1)/4){
			v1.pb(4*i + 1 + j);
			v1.pb(4*i + 4 + j);
			v2.pb(4*i + 2 + j);
			v2.pb(4*i + 3 + j);  
		}

		cout<<v1.size()<<endl;
		for(auto n:v1)
			cout<<n<<" ";
		cout<<endl<<v2.size()<<endl;
		for(auto n:v2)
			cout<<n<<" ";
		cout<<endl;

	}

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("D:\\CODING\\CSES\\input.txt", "r", stdin);
	freopen("D:\\CODING\\CSES\\output.txt", "w", stdout);
	#endif

	fast;
	ll t = 1;

	while(t--){
		solve();
	}
}