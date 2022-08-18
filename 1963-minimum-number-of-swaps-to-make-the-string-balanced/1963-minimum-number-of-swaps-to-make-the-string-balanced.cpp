class Solution {
public:
    int minSwaps(string s) {
        int open=0,swaps=0;
        for(char& c:s){
            if(c=='[')  open++;
            else{
                if(open>0)  open--;
                else{
                    swaps++;
                    open++;
                }
            }
            
        }
        return swaps;
        
    }
};