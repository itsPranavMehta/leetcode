class Solution {
public:
    string reformatNumber(string number) {
        string answer;
        for(auto& num:number){
            if(num>='0' && num<='9'){
                answer.push_back(num);
            }
        }
        int i=3;
        if(answer.size()<5) i=2;
        while((i<=(int)answer.size()-6) || (i==(int)answer.size()-5) || (i==(int)answer.size()-3)){
            answer.insert(i,1,'-');
            i+=4;
        }
        while(i<=(int)answer.size()-2){
            answer.insert(i,1,'-');
            i+=3;
        }
        return answer;
        
    }
};