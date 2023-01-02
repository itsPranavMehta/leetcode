//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector<int> dp(N+1,INT_MAX);
        dp[0]=INT_MIN;
        for(int i=0;i<N;i++){
            int j=distance(dp.begin(),upper_bound(dp.begin(),dp.end(),H[i]));
                if(H[i]>dp[j-1] && H[i]<dp[j]){
                    dp[j]=H[i];
            }
        }
        int res=0;
        for(int i=1;i<=N;i++){
            if(dp[i]!=INT_MAX)  res=max(res,i);
        }
        return N-res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends