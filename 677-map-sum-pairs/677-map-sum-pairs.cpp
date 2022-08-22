class MapSum {
private:
    class Trie{
        public:
        vector<Trie*> children;
        int val;
        Trie(){
            val=0;
            children.assign(26,nullptr);
        }
    };
    
    void addString(string& s,int val,Trie* main_head){
        Trie* head=main_head;
        for(auto& c:s){
            if(head->children[c-'a']==nullptr){
                head->children[c-'a']=new Trie();
            }
            head=head->children[c-'a'];
        }
        head->val=val;                     // add to the end.
    }
    
    int calculateSum(string s,Trie* main_head){
        int sum=0;
        Trie* head=main_head;
        for(auto& c:s){
            if(head->children[c-'a']!=nullptr){
                head=head->children[c-'a'];
            }
            else{               // if I can't match all the characters in the string itself then there's no point exploring further.
                return 0;
            }
        }
        sum+=head->val;    
        for(int i=0;i<26;i++){
            if(head->children[i]!=nullptr){
                sum+=calculateSum(string(1,'a'+i),head);
            }
        }
        return sum;
    }
public:
    Trie* head;
    MapSum() {
        head=new Trie();
    }
    
    void insert(string key, int val) {
        addString(key,val,head);
    }
    
    int sum(string prefix) {
        return calculateSum(prefix,head);
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */