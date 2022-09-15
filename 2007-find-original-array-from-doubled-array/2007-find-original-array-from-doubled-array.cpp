class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        unordered_map<int,int> cancel;
        vector<int> originalArray;
        for(auto& i:changed){
            if(cancel[i]!=0){
                cancel[i]--;
            }
            else{
                cancel[2*i]++;
                originalArray.push_back(i);
            }
        }
        return originalArray.size()*2==changed.size()?originalArray:vector<int>();
        
    }
};