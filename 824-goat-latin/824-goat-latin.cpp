class Solution {
private:
    bool isVowel(char c){
        c=tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    
public:
    string toGoatLatin(string sentence) {
        string token="",ans;
        int idx=1;
        istringstream ss(sentence);
        
        while(getline(ss,token,' ')){
            if(isVowel(token[0])){
                ans+=token;
            }
            else{
                ans+=token.substr(1)+token[0];
            }
            ans+="ma";
            ans.insert(ans.end(),idx,'a');
            ans.push_back(' ');
            idx++;
            
        }
        ans.pop_back();
        return ans;
        
    }
};