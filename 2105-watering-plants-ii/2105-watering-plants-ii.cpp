class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a=0,b=plants.size()-1;
        int currA=capacityA,currB=capacityB;
        int refils=0;
        while(a<b){
            currA-=plants[a];
            currB-=plants[b];
            if(currA<0) currA=capacityA-plants[a],refils++;
            if(currB<0) currB=capacityB-plants[b],refils++;
            a++;
            b--;
        }
        if(a==b){
            refils=refils+(currA<plants[a] && currB<plants[a]);
        }
        return refils;
        
    }
};