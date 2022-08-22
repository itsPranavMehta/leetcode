class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int moves=0;
        while(s.size()){
            auto pos=s.find(s.back());
            if(pos==s.size()-1){        //single occurence  hence should be placed in the middle
                moves+=s.size()/2;
            }
            else{
                moves+=pos;
                s.erase(pos,1);
            }
            s.pop_back();
        }
        return moves;
        
    }
};