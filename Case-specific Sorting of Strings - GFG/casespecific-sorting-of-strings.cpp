//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    string caseSort(string str, int n)
    {
        string lo,hi;
        for(auto& c:str){
            if(c<'a')   hi.push_back(c);
            else lo.push_back(c);
        }
        sort(lo.begin(),lo.end());
        sort(hi.begin(),hi.end());
        int a=0,b=0,x=lo.size(),y=hi.size();
        while(a<x || b<y){
            if(str[a+b]<'a')    str[a+b]=hi[b++];
            else str[a+b]=lo[a++];
        }
        return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends