class Solution {
public:
    int concatenatedBinary(int n) 
    {
        unsigned long int num=0;
        int m=1e9+7;
        for(int i=1;i<=n;i++)    
        {
            num<<=((int)ceil(log2(i+1)));
            num+=i;
            num%=m;
            
        }
        return num;
    }
};