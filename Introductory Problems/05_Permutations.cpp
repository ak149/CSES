#include<bits/stdc++.h>

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

using namespace std;


void solve(){

	ll n;	
	cin>>n;

	if(n == 1){
		cout<<1<<endl;
		return;
	}

	if(n == 2 || n == 3){
		cout<<"NO SOLUTION"<<endl;
		return;
	}

	if(n == 4){
		cout<<"2 4 1 3"<<endl;
		return;
	}
	if(n&1){
		ll k = n - 1;
		ll l = n;


		while(k >= 2){
			cout<<k<<" ";
			k-=2;
		}

		
		while(l >=1){
			cout<<l<<" ";
			l-=2;
		}


	}
	else{
		ll k = n;
		ll l = n-1;

		while( k >=2){
			cout<<k<<" ";
			k-=2;
		}

		
		while(l >=1){
			cout<<l<<" ";
			l-=2;
		}
	}
	
	cout<<endl;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	fast;
	ll t = 1;


	while(t--){
		solve();
	}
}
