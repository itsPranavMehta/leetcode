class Solution {
public:
    string posn(string n,int x){    // try to maximise the magnitude
        for(int i=0;i<n.size();i++){
            if(n[i]<x+'0'){
                n.insert(i,1,'0'+x);
                return n;
            }
        }
        n.push_back('0'+x);
        return n;
    }
    string negn(string n,int x){        // skip 1st character (-) and try to minimise the magnitude
        for(int i=1;i<n.size();i++){
            if(n[i]>x+'0'){
                n.insert(i,1,'0'+x);
                return n;
            }
        }
        n.push_back('0'+x);
        return n;
    }
    string maxValue(string n, int x) {
        if(n[0]=='-')   return negn(n,x);
        return posn(n,x);
    }
};