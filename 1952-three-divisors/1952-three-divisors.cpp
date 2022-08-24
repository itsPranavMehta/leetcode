class Solution {
public:
    bool isThree(int n) {
        int numDiv=0;
        for(int i=1;i<=sqrt(n) && numDiv<3;i++){
            if(n%i==0){
                if(i==sqrt(n))  numDiv++;
                else numDiv+=2;
            }
        }
        return numDiv==3;
        
    }
};