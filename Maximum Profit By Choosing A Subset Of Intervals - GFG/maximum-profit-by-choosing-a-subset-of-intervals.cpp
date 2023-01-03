//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // sort -> 
        // 1st element of the arrray ! 
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]!=b[1]?a[1]<b[1]:(a[0]!=b[0]?a[0]<b[0]:a[2]>b[2]);
        });
        
        map<int,int> profits;       // sorted ,,, 
        // lower bound and upper bound 
        
        // lowerbound(x) -> x or greater than x (smallest possible val)
        // upperbound(x) -> greater than x.... 
        
        profits[-1]=0;      // time -1=0; /
        
        for(auto& interval: intervals){
            
            int s=interval[0],e=interval[1],p=interval[2];
            
            int mxProfit=max((prev(profits.upper_bound(e)))->second,
            (prev(profits.upper_bound(s)))->second+p);
            profits[e]=mxProfit;
        }
        return profits.rbegin()->second;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends