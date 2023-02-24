//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int mn=arr[0]+k,mx=arr[n-1]+k;      // if I only add K to all elements!
        int res=mx-mn;
        for(int i=1;i<n;i++){       // uptill i-1 index I add k and after than I subtract k
            if(arr[i]-k<0)  continue;       // can't have negative values
            mx=max(arr[i-1]+k,arr[n-1]-k);
            mn=min(arr[0]+k,arr[i]-k);
            res=min(res,mx-mn);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends