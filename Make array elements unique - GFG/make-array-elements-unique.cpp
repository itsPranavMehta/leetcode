//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(),arr.end());
        long long initialSum=accumulate(arr.begin(),arr.end(),0ll);
        int i=1,j=1;
        while(i<N){
            if(arr[i]<=arr[i-1]){
                arr[i]=arr[i-1]+1;
            }
            i++;
        }
        return accumulate(arr.begin(),arr.end(),0ll)-initialSum;
        // Code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends