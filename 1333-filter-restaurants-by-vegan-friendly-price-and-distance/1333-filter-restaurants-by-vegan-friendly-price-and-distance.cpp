class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        int count=0;
        for(auto& restaurant:restaurants){
            int price=restaurant[3],distance=restaurant[4];
            bool veg=restaurant[2];
            if(price<=maxPrice && distance<=maxDistance && (!veganFriendly || veg)){
                res.push_back(count);
            }
            count++;
        }
        sort(res.begin(),res.end(),[&](int a,int b){
            if(restaurants[a][1]!=restaurants[b][1])    return restaurants[a][1]>restaurants[b][1];
            return restaurants[a][0]>restaurants[b][0];
            
        });
        for(auto& i:res){
            i=restaurants[i][0];
        }
        return res;
        
    }
};