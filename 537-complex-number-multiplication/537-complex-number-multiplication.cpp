class Solution {
    string solve(string& r1, string& r2,string& c1,string& c2){
        int x1=stoi(r1),x2=stoi(r2),y1=stoi(c1),y2=stoi(c2);
        string r=to_string(x1*x2-y1*y2);
        string c=to_string(x1*y2+x2*y1);
        return r+"+"+c+"i";
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        string real1=num1.substr(0,num1.find('+')), real2=num2.substr(0,num2.find('+'));
        string complex1=num1.substr(num1.find('+')+(num1[num1.find('+')+1]=='-')), 
        complex2=num2.substr(num2.find('+')+(num2[num2.find('+')+1]=='-'));
        complex1.pop_back(),complex2.pop_back();
        return solve(real1,real2,complex1,complex2);
        
    }
};