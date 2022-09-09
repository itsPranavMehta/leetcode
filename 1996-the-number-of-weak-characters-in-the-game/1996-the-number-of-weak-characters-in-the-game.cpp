class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.rbegin(),properties.rend());
        int maxDefence=0,weakCharacters=0;
        int temporaryStoreForDefence=properties[0][1];
        for(int idx=1;idx<properties.size();idx++){
            int defence=properties[idx][1];
            
            if(properties[idx][0]!=properties[idx-1][0])        //if previous attack was different then use it to change
            {
                maxDefence=max(maxDefence,temporaryStoreForDefence);
            }
            if(maxDefence>defence){
                weakCharacters++;
            }
            if(idx!=properties.size()-1 && properties[idx][0]!=properties[idx+1][0] ){
                maxDefence=max(maxDefence,defence);
            }
            else{
                temporaryStoreForDefence=max(temporaryStoreForDefence,defence);
            }
        }
        return weakCharacters;
    }
};