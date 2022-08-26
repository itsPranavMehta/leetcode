class Solution {
public:
    int minimumSum(int num) {
        vector<int> vals;
        while(num){
            vals.push_back(num%10);
            num/=10;
        }
        sort(vals.begin(),vals.end());
        return (vals[0]+vals[1])*10+vals[2]+vals[3];
    }
};