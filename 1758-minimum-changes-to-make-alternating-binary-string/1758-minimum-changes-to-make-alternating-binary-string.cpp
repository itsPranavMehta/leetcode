class Solution {
public:
    int minOperations(string s) {
        int mn=INT_MAX,curr=0;
        for(int i=0;i<s.size();i++){
            if(i%2 && s[i]!='0'){
                curr++;
            }
            else if(i%2==0 && s[i]!='1')    curr++;
        }
        mn=min(mn,curr);
        curr=0;
        for(int i=0;i<s.size();i++){
            if(i%2 && s[i]!='1'){
                curr++;
            }
            else if(i%2==0 && s[i]!='0')    curr++;
        }
        mn=min(mn,curr);
        return mn;
        
    }
};