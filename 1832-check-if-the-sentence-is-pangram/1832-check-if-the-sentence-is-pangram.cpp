class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask=0;
        for(auto& c:sentence){
            mask=mask|(1<<(c-'a'));
        }
        return mask==(1<<26)-1;
        
    }
};