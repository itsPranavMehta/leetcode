class Solution {
public:
    string getHappyString(int n, int& k,char last_ch='0',int sz=0) { // just a default wrong entry
        if(sz==n){
            k--;
            return "";
        }
        for(char c='a';c<='c';c++){
            if(c!=last_ch){
                string curr=getHappyString(n,k,c,sz+1);
                if(k==0) return string(1,c)+curr;
            }
        }
        return "";
        
        
    }
};