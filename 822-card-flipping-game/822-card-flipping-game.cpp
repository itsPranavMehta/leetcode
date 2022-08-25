class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> valids,invalids;   // invalids is only for those which appear on both heads in the card
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]==backs[i]){
                if(valids.count(fronts[i]))  valids.erase(fronts[i]);
                invalids.insert(fronts[i]);
            }
            else{
                if(!invalids.count(fronts[i]))   valids.insert(fronts[i]);
                if(!invalids.count(backs[i]))   valids.insert(backs[i]);
                
            }
        }
        return valids.size()?*valids.begin():0;
    }
};