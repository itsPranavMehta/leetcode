class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v={a,b,c};
        sort(v.begin(),v.end());
        v[2]=min(v[0]+v[1],v[2]);
        return accumulate(v.begin(),v.end(),0)/2;
    }
};