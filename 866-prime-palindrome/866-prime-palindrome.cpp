class Solution {
private:
    string buildNextPalindrome(string s){
        if(string(s.size(),'9')==s){                // if max has been reached
            return "1"+string(s.size()-1,'0')+"1";
        }
        if(s.size()%2){ // contains a center element then it's easiest to increase it.
            if(s[s.size()/2]!='9'){
                s[s.size()/2]++;
                return s;
            }
        }
        int l=s.size()/2-1;
        while(s[l]=='9')    l--;
        s[l]++;
        s[s.size()-l-1]++;
        fill(s.begin()+l+1,s.begin()+s.size()-l-1,'0');
        return s;
    }
    
    bool isPrime(string& s){
        int n=stoll(s);
        if(n<4) return n-1;             //false for 1 true for rest
        for(int fac=2;fac<=sqrt(n);fac++){
            int mul=n/fac;
            if(fac*mul==n)  return 0;
        }
        return 1;
    }
    
    string buildFirstPal(string& s){
        int l=s.size()/2-1;
        bool isSmaller=false;   // to be set true if the string being formed is becoming less than original
        while(l>=0 && s[l]==s[s.size()-l-1])   l--;
        if(l==-1)    return s;                  // already a palindrome
        else if(s[l]<s[s.size()-l-1]){
            isSmaller=true;
        }
        while(l>=0){
            s[s.size()-l-1]=s[l];
            l--;
        }
        if(isSmaller){
            int l=s.size()/2-(s.size()%2==0);
            while(l>=0){
                if(s[l]!='9'){
                    s[l]++;
                    if(l!=s.size()/2)
                    {
                        s[s.size()-l-1]++;
                        fill(s.begin()+l+1,s.begin()+s.size()-l-1,'0'); //make all inner elements 0
                    }
                    break;
                }
                l--;
            }
        }
        return s;
    }
    
    
public:
    int primePalindrome(int n) {
        // I can check for prime in sqrt(n), also number of palindromes are pretty less hence it would e
        string s=to_string(n);
        s=buildFirstPal(s);
        int count=0;
        while(!isPrime(s)){
            s=buildNextPalindrome(s);
        }
        return stoi(s);
        
    }
};