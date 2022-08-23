class Solution {
public:
    int mirrorReflection(int p, int q) {
        int fac=1;
        while((p*fac)%q!=0) ++fac;
        p*=fac;
        if(fac%2==1){           
            if((p/q)%2==0)    return 2;
            return 1;
        }
        else    return 0;
    }
};
