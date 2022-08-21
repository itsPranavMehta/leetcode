class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        for(int idx=0;idx<num.size();idx++){
            if(num[idx]-'0'<change[num[idx]-'0']){
                while(idx<num.size() && num[idx]-'0'<=change[num[idx]-'0']){
                    num[idx]='0'+change[num[idx]-'0'];
                    idx++;
                }
                return num;
            }
        }
        return num;
        
    }
};