class Solution {
private:
    int mod=1337;
    int pow(int x,int y){
        if(y==0 || x==1)    return 1;
        x%=mod;
        int res=x;
        while(--y)  res=(res*x)%mod;
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        
        // so we know a^123=a^120.a^3 [basic maths]
        // further a^120=(a^12)^10
        if(b.empty())   return 1;
        int lastDigit=b.back();
        b.pop_back();
        return (pow(superPow(a,b),10)*pow(a,lastDigit))%mod;
    }
};