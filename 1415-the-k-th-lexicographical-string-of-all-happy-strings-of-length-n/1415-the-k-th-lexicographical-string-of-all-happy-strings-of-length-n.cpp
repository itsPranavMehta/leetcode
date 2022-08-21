class Solution {
public:
    string getHappyString(int n, int& k,char last_ch='z',string curr="") { // just a default wrong entry
        if(curr.size()==n){
            k--;
            if(k==0)    return curr;
            return "";
        }
        for(char c='a';c<='c';c++){
            if(c!=last_ch){
                curr.push_back(c);
                string ans=getHappyString(n,k,c,curr);
                if(ans!="") return ans;
                curr.pop_back();
            }
        }
        return "";
        
        
    }
};