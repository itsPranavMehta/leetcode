class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> unique_codes;
        
        for(auto& word: words){
            string code;
            
            for(auto& ch: word){
                code+=morse_code[ch-'a'];
            }
            unique_codes.insert(code);
        }
        return unique_codes.size();
        
    }
};