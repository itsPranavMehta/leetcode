//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        int min_operations_till_i = 0 , median;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            median = a[i/2];
            min_operations_till_i+=a[i]-median;
            ans[i] = min_operations_till_i;
        }
        return ans;
}
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends