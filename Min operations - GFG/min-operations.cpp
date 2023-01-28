//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        bool A=false,B=false;
        for(int i=0;i<30;i++){
            if(((1<<i)&a) && !((1<<i)&b))   A=true;
            if(((1<<i)&b) && !((1<<i)&a))   B=true;
            
        }
        return (A?1:0)+(B?1:0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends