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
		int op;
		cin>>op;

		if(op == 1){
			int i,v;
			cin>>i>>v;
			sg.set(i - 1,v);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<sg.findMin(l - 1,r)<<endl;
		}
	}

	// sg.printTree();

}