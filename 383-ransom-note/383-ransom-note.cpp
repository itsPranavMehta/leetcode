class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        for(auto& i:magazine)    freq[i-'a']++;
        for(auto& i:ransomNote ){
            if(!freq[i-'a'])    return 0;
            freq[i-'a']--;
        }
        return 1;
    }
};