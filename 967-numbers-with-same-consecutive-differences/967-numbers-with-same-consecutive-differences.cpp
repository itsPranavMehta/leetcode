class Solution {
    void helper(int n,int k,int num,vector<int>& res){
        if(num==0){
            for(int i=1;i<=9;i++){
                helper(n,k,i,res);
            }
        }
        
        else if(num>=pow(10,n-1)){
            res.push_back(num);
        }
        
        else{
            int lastDigit=num%10;
            int currDigit=lastDigit+k;
            if(currDigit<=9){
                helper(n,k,num*10+currDigit,res);
            }
            currDigit=lastDigit-k;
            if(lastDigit-k!=lastDigit+k && currDigit>=0){
                helper(n,k,num*10+currDigit,res);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        helper(n,k,0,res);
        return res;
    }
};