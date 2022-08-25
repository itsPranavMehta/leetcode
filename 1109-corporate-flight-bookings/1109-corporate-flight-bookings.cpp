class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int,int> mp;
        for(auto& booking: bookings){
            mp[booking[0]-1]+=booking[2];
            mp[booking[1]]-=booking[2];
        }
        vector<int> res(n,0);
        res[0]=mp[0];
        for(int i=1;i<n;i++){
            res[i]=mp[i]+res[i-1];
        }
        return res;
    }
};