class Encrypter {
private:
    class Trie{
    public:
        vector<Trie*> children;
        bool isEnd;
        Trie(){
            children.assign(26,nullptr);
            isEnd=false;
        }
    };
    
    void add(Trie* head,string& s){
        Trie* curr=head;
        for(auto& ch:s){
            int idx=ch-'a';
            if(!curr->children[idx])    curr->children[idx]=new Trie();
            curr=curr->children[idx];
        }
        curr->isEnd=true;
    }
    Trie* search(Trie* head,char c){
        Trie* curr=head;
        int idx=c-'a';
        if(!curr->children[idx])    return nullptr;
        curr=curr->children[idx];
        return curr;
    }
    
    unordered_map<string,vector<char>> valuesToKeys;
    unordered_map<char,string> keysToValues;
    Trie* head;
public:
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        head=new Trie();
        for(auto& i:dictionary) add(head,i);

        for(int i=0;i<keys.size();i++){
            valuesToKeys[values[i]].push_back(keys[i]);
            keysToValues[keys[i]]=values[i];
        }
        
    }
    
    string encrypt(string word1) {
        string enc;
        for(auto& i: word1){
            if(keysToValues.count(i)){
                enc+=keysToValues[i];
            }
            else return "";
        }
        return enc;
    }
    
    void getAllValidStrings(Trie* curr, string& decrypted,string& enc,int& valids,int idx=0){
        if(idx==decrypted.size()){
            if(curr->isEnd) valids++;
            return;
        }
        
        for(auto& i:valuesToKeys[decrypted.substr(idx,2)]){
            Trie* nxt=search(curr,i);
            if(nxt!=nullptr){
                enc.push_back(i);
                getAllValidStrings(nxt,decrypted,enc,valids,idx+2);
                enc.pop_back();
            }
        }
    }
    
    int decrypt(string word2) {
        vector<string> possibleStrings;
        int res=0;
        string s;
        getAllValidStrings(head,word2,s,res);
        return res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */