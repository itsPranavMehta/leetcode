class Solution {
private:
    bool isInitialPermutation(vector<int>& a){
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]!=i)return 0;
        }
        return 1;
    }
    void permute(vector<int>& a){
        vector<int> t(a.size(),0);
        for(int i=0;i<a.size();i++){
            if(i%2) t[i]=a[a.size()/2 +(i-1)/2];
            else t[i]=a[i/2];
        }
        a.assign(t.begin(),t.end());
    }
public:
    int reinitializePermutation(int n) {
        vector<int> vec(n,0);
        iota(vec.begin(),vec.end(),0);
        permute(vec);
        int ops=1;
        while(!isInitialPermutation(vec)){
            permute(vec);
            ops++;
            
        }
        return ops;
    }
    
};
