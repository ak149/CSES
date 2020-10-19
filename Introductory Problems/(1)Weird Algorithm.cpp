#include<iostream>
using namespace std;

#define ll long long int
	
int main(){
	ll n;
	cin>>n;

	while(n >1){

		cout<<n<<" ";
		if(n== 1)
			break;
		if( n%2 == 0)
			n/=2;
		else{
			n = 3*n + 1;
		}
	}
	cout<<1<<" ";
}