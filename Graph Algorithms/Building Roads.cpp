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


using namespace std;

vector<ll> edges[200005];
vector<bool> visited(200005);

void dfs(ll sv){
	visited[sv] = true;

	for(auto v: edges[sv]){
		if(visited[v] == false){
			dfs(v);
		}
	}

	return;
}

void solve(){

	ll n,m;
	cin>>n>>m;

	for(ll i=0;i<m;i++){
		ll u,v;
		cin>>u>>v;

		edges[u-1].pb(v-1);
		edges[v-1].pb(u-1);
	}
	
	fori(i,0,n){
		visited[i] = false;
	}

	vector<ll> temp;
	for(ll i=0;i<n;i++){
		if(visited[i] == false){
			temp.pb(i);
			dfs(i);
		}
	}

	ll count = temp.size() - 1;
	cout<<count<<endl;
	for(ll i=0;i<count;i++){
		cout<<temp[i] + 1<<" "<<temp[i+1] + 1<<endl;
	}

	return;
}


int main(){

	fast;
	ll t = 1;

	while(t--){
		solve();
	}
}
