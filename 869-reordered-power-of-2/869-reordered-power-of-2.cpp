class Solution {
private:
    bool isAnagram(int n,int x){
        vector<int> vec(10,0);
        while(n){
            vec[n%10]++;
            n/=10;
        
        }
        while(x){
            vec[x%10]--;
            x/=10;
        }
        for(auto& i:vec)    if(i!=0)    return 0;
        return 1;
    }
    int countDigs(int n){
        int count=0;
        while(n){
            n/=10;
            count++;
        }
        return count;
    }
    int smallestNumber(int n){
        int l=0,r=31;
        int best_ans=0;
        while(l<=r){
            int m=(l+r+1)/2;
            if(countDigs(pow(2,m))>=n){
                best_ans=pow(2,m);
                r=m-1;
            }
            else{
                l=m+1;
            }  
        }
        return best_ans;
        
    }
public:
    bool reorderedPowerOf2(int n) {
        // so the power of 2 for any digit (say n) can at max be 4.. hence i'll calculate all the power of 2s in that many digit and would check if it's possible to make that number by rearranging those..
        int smallest_valid=smallestNumber(countDigs(n));
        while(countDigs(smallest_valid)==countDigs(n)){
            if(isAnagram(n,smallest_valid)) return 1;
            smallest_valid<<=1;
        }
        return 0;
        
    }
};