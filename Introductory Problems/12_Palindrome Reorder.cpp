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

	string s;
	cin>>s;
	// cout<<s<<endl;
	vector<ll> frealpha(26,0);
	for(auto ch:s){
		frealpha[ch - 'A']++;
	}

	int countodd = 0;
	for(auto fre:frealpha){
		if(fre%2 == 1){
			countodd++;
		}
	}
	// cout<<countodd<<endl;
	if(countodd > 1){
		cout<<"NO SOLUTION"<<endl;
		return;
	}
	else{
		string op = "";
		int oddchar = INT_MAX;
		for(int i = 0 ;i < 26 ;i++){
			if(frealpha[i]&1)
				oddchar = i;
		}

		for(int i = 0 ;i < 26;i++){
			if(frealpha[i]&1)
				continue;
			int j = frealpha[i]/2;
			frealpha[i] /= 2;
			char ch = 'A' + i;
			while(j--){
				op = op + ch;
			}
		}
		char oddch = '\0';
		if(oddchar != INT_MAX){
			char oddch = 'A' + oddchar;
			while(frealpha[oddchar]--){
				op = op + oddch;
			}
		}

		// for(int i = 0; i < 26 ; i++){
		// 	char ch = 'A' + i;

		// 	cout<<"fre of"<<ch<<" : "<<frealpha[i]<<endl;
		// }

		for(int i = 25 ;i >= 0 ;i--){
			char ch = 'A' + i;
			if(ch == oddch)
				continue;
			int j = frealpha[i];
			while(j--){
				op = op + ch;
			}
		}

		cout<<op<<endl;
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