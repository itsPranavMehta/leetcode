class Solution {
public:
    void possiblePermutation(int n,string& curr,vector<string>& allPermutations){
        if(n==curr.size()){
            allPermutations.push_back(curr);
            return;
        }
        vector<char> chars={'a','b','c'};
        for(auto& c:chars){
            if(!curr.size() || curr.back()!=c){
                curr.push_back(c);
                possiblePermutation(n,curr,allPermutations);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        // considering the constraint- brute force should work but this should have a easy mathematical solution as well...
        vector<string> allPermutations;
        string currPerm;
        possiblePermutation(n,currPerm,allPermutations);
        sort(allPermutations.begin(),allPermutations.end());
        
        return allPermutations.size()>=k? allPermutations[k-1]:"";
        
    }
};