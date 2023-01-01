//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    int fac[100005];
    int power(int x,int y,int p=1e9+7){
        unsigned long long X=x;
        unsigned long long res=1;
        while(y>0){
            if(y&1) res=(res*X)%p;
            y/=2;
            X=(1ll*X*X)%p;
        }
        // cout<<res<<"\n";
        return res;
    }
    int modIn(int x,int p=1e9+7){
        return power(x%p,p-2);
    }
    int ncr(int n,int r,int p=1e9+7){
        // cout<<n<<" "<<r<<"\n";
        // cout<<fac[n]<<" "<<fac[r]<<" "<<fac[n-r]<<"\n";
        return ((1ll*fac[n]*modIn(fac[n-r]))%p)*modIn(fac[r])%p;
    }
	public:
	int compute_value(int n)
	{
	    memset(fac,0,(n+1)*(sizeof(int)) );
	    fac[0]=1;
	   // cout<<modIn(1)<<"\n";
	    int p=1e9+7,res=0;
	    for(int i=1;i<=n;i++)    fac[i]=(1ll*i*fac[i-1])%p;
	    
	    for(int i=0;i<=n;i++){
	        long long v=ncr(n,i);
	       // cout<<v<<" "<<v*v<<"\n";
	        res=(res+1ll*v*v)%p;
	       // cout<<res<<"\n";
	    }
	   // cout<<res<<"\n";
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends