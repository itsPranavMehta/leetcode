class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        for(auto& c:s){
            freq[c-'a']++;
        }
        for(auto& c:t){
            freq[c-'a']--;
        }
        for(auto& i:freq)   if(i!=0)    return 0;
        return 1;
    }
};