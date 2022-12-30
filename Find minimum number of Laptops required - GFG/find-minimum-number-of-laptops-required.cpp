//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        map<int,int> laps;
        for(int i=0;i<N;i++)    laps[start[i]]++,laps[end[i]]--;
        int curr=0,res=0;
        for(auto it=laps.begin();it!=laps.end();it++){
            curr+=it->second;
            res=max(res,curr);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends