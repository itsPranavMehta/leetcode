class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heaps;
        for(auto& pile:piles)   heaps.push(pile);
        
        while(k--){
            heaps.push(heaps.top()-heaps.top()/2);
            heaps.pop();
        }
        int sum=0;
        while(heaps.size()){
            sum+=heaps.top();
            heaps.pop();
        }
        return sum;
        
    }
};