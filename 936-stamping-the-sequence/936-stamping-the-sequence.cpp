class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        //adding comment in leethub
        
        vector<int> seq;
        int totalStamped=0,currStamped=1;   // just to start while loop
        while(currStamped){
            currStamped=0;
            for(int sz=stamp.size();sz>0;sz--){        // size of the stamp for the iteration;
                for(int l=0;l<=stamp.size()-sz;l++){    // number of * to the left;
                    string currentStamp=string(l,'*')+stamp.substr(l,sz)+string(stamp.size()-sz-l,'*');
                    auto pos=target.find(currentStamp);
                    while(pos!=string::npos){
                        fill(target.begin()+pos,target.begin()+pos+stamp.size(),'*');
                        currStamped+=sz;
                        seq.push_back(pos);
                        pos=target.find(currentStamp);
                    }
                }
            }
            totalStamped+=currStamped;
        }
        reverse(seq.begin(),seq.end());
        return totalStamped==target.size()?seq:vector<int>();
        
    }
};