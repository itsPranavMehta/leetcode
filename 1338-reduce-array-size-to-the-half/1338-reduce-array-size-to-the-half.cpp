class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        multiset<int,greater<int>>frequencies;

        for(int idx=0;idx<arr.size();idx++){
            int freq=1;
            while(idx<arr.size()-1 && arr[idx]==arr[idx+1]){   
                idx++;
                freq++;
            }
            frequencies.insert(freq);
        }
        int removedElements=0, count=0;
        for(auto it=frequencies.begin();it!=frequencies.end() && removedElements*2<arr.size();it++){
            removedElements+=*it;
            count++;
        }
        return count;
        
    }
};