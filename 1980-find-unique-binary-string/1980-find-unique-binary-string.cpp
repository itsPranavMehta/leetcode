class Solution {
private:
    int convertBinaryToDecimal(string& s){
        int ans=0;
        for(auto& i:s){
            ans<<=1;
            if(i=='1')  ans++;
        }
        return ans;
    }
    string convertDecimalToBinary(int n,int sz){
        string bin;
        while(n){
            if(n%2) bin+="1";
            else bin+="0";
            n>>=1;
            sz--;
        }
        while(sz--) bin+="0";
        reverse(bin.begin(),bin.end());
        return bin;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int sum=0,n=nums[0].size();
        vector<bool> pres(pow(2,n),0);
        for(auto& num:  nums){
            pres[convertBinaryToDecimal(num)]=1;
        }
        for(int i=0;i<pow(2,n);i++){
            if(!pres[i])    return convertDecimalToBinary(i,n);
        }
        return "";
    }
};
