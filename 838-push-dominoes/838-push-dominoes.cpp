class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int>  q;
        int n=dominoes.size();
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++){
            if(dominoes[i]!='.'){
                q.push(i);
                visited[i]=1;
            }
        }
        while(q.size()){
            int sz=q.size();
            unordered_map<int,int> mp;
            while(sz--){
                int i=q.front();
                q.pop();
                if(i-1>=0 && dominoes[i]=='L' && !visited[i-1])  mp[i-1]+=1;
                if(i+1<n && dominoes[i]=='R' && !visited[i+1])  mp[i+1]+=-1;
            }
            for(auto& i:mp){
                
                visited[i.first]=1;
                if(i.second!=0){
                    
                    q.push(i.first);
                    dominoes[i.first]=(i.second==1?'L':'R');
                }
            }
        }
        return dominoes;
    }
};