class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int currentSum=accumulate(rolls.begin(),rolls.end(),0);
        int totalSum=mean*(n+rolls.size());
        int i=0;
        vector<int> res;
        while(currentSum+(n-i)<totalSum){
            int currentFace=min(6,totalSum-currentSum-(n-i-1));
            currentSum+=currentFace;
            res.push_back(currentFace);
            i++;
        }
        while(currentSum++<totalSum) res.push_back(1);
        return res.size()!=n?vector<int>():res;
        
    }
};