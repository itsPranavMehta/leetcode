class Solution {
private:
    // returns 0 if can be 1st and only byte
    // returns 1 if it can be a middle byte
    // returns n, if it's starting byte which would have n-1 bytes ahead.
    int whichByte(int n){       
        string bin;
        if(n<128)   return 0;
        if(n>=128 && n<192) return 1;
        while(n){
            if(n%2) bin+="1";
            else bin+="0";
            n/=2;
        }
        reverse(bin.begin(),bin.end());
        return bin.find('0'); 
    }
public:
    bool validUtf8(vector<int>& data) {
        bool valid=true;
        int numberOfExpectedBytes=0;
        for(auto& d:data){
            int bytes=whichByte(d);
            if(bytes>4) return 0;
            
            if(numberOfExpectedBytes!=0 ^ bytes==1)    return 0;
            
            if(bytes==1)    numberOfExpectedBytes--;
            else if(bytes!=0) numberOfExpectedBytes=bytes-1;
        }
        return numberOfExpectedBytes==0;
        
        
    }
};