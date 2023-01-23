//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char> st;
        for(auto& c:s){
            st.push(c);
            while(st.size()>=2){
                int ctop=st.top();
                st.pop();
                int ctop2=st.top();
                st.pop();
                if(ctop2!=ctop){
                    st.push(ctop2);
                    st.push(ctop);
                    break;
                }
            }
        }
        if(st.empty())  return "-1";
        s="";
        while(st.size())    {
            s.push_back(st.top());
            st.pop();
            
        }
        reverse(s.begin(),s.end());
        return s;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends