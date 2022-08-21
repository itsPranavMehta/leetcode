class Solution {
private:
    void construct(vector<int>& digits,vector<bool>& avail,set<int>& perms,int curr){
        if(curr/100!=0){
            if(curr%2==0)   perms.insert(curr);
            return;
        }
        for(int idx=0;idx<digits.size();idx++){
            if(avail[idx] && (digits[idx]!=0 || curr!=0)){
                curr*=10;
                curr+=digits[idx];
                avail[idx]=0;
                construct(digits,avail,perms,curr);
                avail[idx]=1;
                curr/=10;
            }
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<bool> avail(n,1);
        set<int> perms;
        construct(digits,avail,perms,0);
        return vector<int>(perms.begin(),perms.end());
        
    }
};