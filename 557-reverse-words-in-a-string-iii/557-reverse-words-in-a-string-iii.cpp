class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string token, res;
        while(getline(ss,token,' ')){
            if(token!=" "){
                reverse(token.begin(),token.end());
                res+=token;
                res+=" ";
            }
        }
        res.pop_back();
        return res;
        
    }
};