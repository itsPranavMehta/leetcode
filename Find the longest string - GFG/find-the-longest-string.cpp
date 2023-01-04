//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        sort(words.begin(),words.end(),[](string& a,string& b){
            return a.size()!=b.size()?a.size()<b.size():a<b;
        });
        unordered_set<string> seen;
        string res="";
        for(auto& word: words){
            if(word.size()==1 || (seen.count(word.substr(0,word.size()-1)))){
                seen.insert(word);
                if(res.size()<word.size())  res=word;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends