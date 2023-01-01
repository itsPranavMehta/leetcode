//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    int power(int x,int y,int p=1e9+7){
        long long res=1;
        while(y>0){
            if(y&1) res=(res*x)%p;
            y/=2;
            x=(1ll*x*x)%p;
        }
        return res;
    }
    int modIn(int x,int p=1e9+7){       // uses fermat little thm.
        return power(x,p-2);  
    }

	public:
	int compute_value(int n)
	{
	    int p=1e9+7,res=1;      // nc0 =1 so storing it
	    int ncr=1;  // nc0
	    for(int r=1;r<=n;r++){// ncr =(( n+1-r)/r)*nC(r-1)
	        ncr=(((1ll*(n-r+1)*ncr)%p)*modIn(r))%p;
	        res=(res+1ll*ncr*ncr)%p;
	    }
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