class Solution {
public:
    int continuousSegmentLength(string& s,char c){
        int longest_segment=0,current_segment=0;
        for(auto& ch: s){
            if(ch==c){
                current_segment++;
                longest_segment=max(longest_segment,current_segment);
            }
            else{
                current_segment=0;         
            }
        }
        return longest_segment;
    }
    bool checkZeroOnes(string s) {
        return continuousSegmentLength(s,'0')<continuousSegmentLength(s,'1');
    }
};