class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {

        int mod=1e9+7;
        #define int long long int
        sort(packages.begin(),packages.end());
        vector<int> prefix_sum(packages.size()+1,0);
        for(int idx=0;idx<packages.size();idx++){
            prefix_sum[idx+1]=packages[idx]+prefix_sum[idx];
        }
        
        int minWastedSpace=LLONG_MAX;
        
        for(auto& seller:boxes){
            sort(seller.begin(),seller.end());
            int package_idx=0,spaceWasted=0;
            for(int idx=0;idx<seller.size();idx++){
                auto ub=upper_bound(packages.begin(),packages.end(),seller[idx]);
                
                if(ub!=packages.begin()){
                    ub=prev(ub);    //so that the iterator points to the index where package<box[idx].
                    int current_package_idx=ub-packages.begin();
                    
                    if(package_idx<=current_package_idx){
                        // int total_sum=(prefix_sum[current_package_idx+1]-prefix_sum[package_idx]+mod)%mod;
                        int total_sum=prefix_sum[current_package_idx+1]-prefix_sum[package_idx];
                        
                        int total_box_capacity=(current_package_idx-package_idx+1ll)*seller[idx];
                        spaceWasted+=(total_box_capacity-total_sum);
                        // spaceWasted%=mod;
                        package_idx=current_package_idx+1;
                        
                    }
                }

            }
            if(package_idx==packages.size()){
                minWastedSpace=min(minWastedSpace, spaceWasted);
            }
        }
        #define int int
        return minWastedSpace==LLONG_MAX?-1:(int)(minWastedSpace%mod);
    }
};