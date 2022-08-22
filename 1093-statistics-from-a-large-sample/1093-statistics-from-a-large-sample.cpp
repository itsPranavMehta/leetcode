class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mn=-1,mx,mean,median=-1,mode;
        int readings=accumulate(count.begin(),count.end(),0);
        long sum=0;
        int mostOccured=0;
        for(int idx=0,numNonZero=0;idx<count.size();idx++){
            int c=count[idx];
            if(c!=0){
                if(mn==-1)  mn=idx;
                mx=idx;
                sum+=(0ll+idx)*c;
                if(mostOccured<c){
                    mostOccured=c;
                    mode=idx;
                }
                if(median==-1 && c*2+numNonZero>=readings){
                    if(c*2+numNonZero==readings)    median=(idx+0.0)/2;
                    else median=idx;
                }
                else if(numNonZero==readings){
                    median+=(idx+0.0)/2;
                }
                numNonZero+=2*c;
            }
        }
        mean=(sum+0.0)/readings;
        
        
        return {mn,mx,mean,median,mode};
        
    }
};