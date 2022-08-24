class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int singleTime=accumulate(amount.begin(),amount.end(),0);
        amount[2]=min(amount[2],amount[1]+amount[0]);
        return singleTime-accumulate(amount.begin(),amount.end(),0)/2;
        
    }
};