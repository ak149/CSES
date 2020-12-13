#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define str string
#define pb push_back
#define vc vector
#define ci cin
#define co cout
ll rmq[1000000],a[1000000];
ll build_rmq(ll idx,ll st,ll en)
{
    if(st==en)
        return rmq[idx]=a[st];
    else
    {
        ll mid=(st+en)/2;
        return rmq[idx]=(build_rmq(2*idx,st,mid)+build_rmq(2*idx+1,mid+1,en));
    }
}
ll query(ll st,ll en,ll l,ll r,ll idx)
{
   
    if(l<=st&&r>=en)
        return rmq[idx];
    if(l>en||r<st)
    {
       return 0;
    }
    //2.Partial overlap
    ll mid=(st+en)/2;
    return (query(st,mid,l,r,2*idx)+query(mid+1,en,l,r,2*idx+1));
}
void update(ll st,ll en,ll i,ll idx,ll diff)
{
   if(i<st||i>en)
    return;
 rmq[idx]=rmq[idx]+diff;
  if(st!=en)
  { ll mid=(st+en)/2;
    update(st,mid,i,2*idx,diff);
    update(mid+1,en,i,2*idx+1,diff);
  }
}
 
int main()
{ 
   
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    build_rmq(1,0,n-1);
   while(m--)
   {
    ll t;
    cin>>t;
    if(t==1)
    {
         ll k,u;
         cin>>k>>u;
         ll diff=u-a[k-1];
         a[k-1]=u;
         k--;
         update(0,n-1,k,1,diff);
    }
    else
    {
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(0,n-1,l,r,1)<<"\n";
    }
   }
    
    
}