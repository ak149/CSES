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
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll power(ll x, ll b,ll m) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= m;} b >>= 1; x *= x; x %= m;} return p % m;}
void dbg(string s){cout<<s<<endl;}

vector<vector<char>> g;
vector<vector<ll>> visited;
ll n,m;
ll shortest_path ;

pll endpt;
pll startpt;



/*
We will store the distances in a 2D array and then backtrack from the end point
to the start point to get the path.
We can not pass the path in the queue like queue<pair<pair<ll,ll>,string>> this will
also work correctly but takes alot of time to copy the path every time into a new 
node and hence gives TLE.
*/
bool isSafe(ll row,ll col){
	return row >= 0 && row < n && col >= 0 && col <= m && visited[row][col] <= 0 && g[row][col] != '#';
}
bool bfs(ll i, ll j){
	queue<pll> pending;
	pending.push({i,j});
	visited[i][j] = 1;


	while(!pending.empty()){
		auto front = pending.front();
		pending.pop();
		ll x = front.fi;
		ll y = front.se;
		ll dist = visited[x][y];

		if(g[x][y] == 'B'){
			shortest_path = dist;
			endpt = {x,y};
			return true;
		}

		if(isSafe(x,y - 1)){
			pending.push({x,y - 1});
			visited[x][y - 1] = dist + 1;
		}

		if(isSafe(x,y + 1)){
			pending.push({x,y + 1});
			visited[x][y + 1] = dist + 1;
		}

		if(isSafe(x - 1,y)){
			pending.push({x - 1,y});
			visited[x - 1][y] = dist + 1;
		}

		if(isSafe(x + 1,y)){
			pending.push({x + 1,y});
			visited[x + 1][y] = dist + 1;
		}
		
	}

	return false;
}

void solve(){

	cin>>n>>m;
	g = vector<vector<char>>(n,vector<char>(m));
	rep(i,n) rep(j,m) cin>>g[i][j];
	visited = vector<vector<ll>>(n,vector<ll>(m,0));
	shortest_path = INT_MAX;
	bool canreach = false;
	rep(i,n){
		rep(j,m){
			if(g[i][j] == 'A'){
				startpt = {i,j};
				canreach = bfs(i,j);
			}
		}
	}
	if(canreach){
		cout<<"YES"<<endl;
		string path = "";
		ll r = endpt.fi;
		ll c = endpt.se;
		while(r != startpt.fi || c != startpt.se){
			
			if(r > 0 && visited[r - 1][c] == visited[r][c] - 1){
				path += "D";
				r--;
			}
			else if(r < n - 1 && visited[r + 1][c] == visited[r][c] - 1){
				path += "U";
				r++;
			}
			else if(c > 0 && visited[r][c - 1] == visited[r][c] - 1){
				path += "R";
				c--;
			}
			else if(c < m - 1 && visited[r][c + 1] == visited[r][c] - 1){
				path += "L";
				c++;
			}
		}

		reverse(all(path));
		cout<<path.size()<<endl<<path;
	}
	else{
		cout<<"NO"<<endl;
	}
	

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