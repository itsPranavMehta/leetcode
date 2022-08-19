class Solution {
string chooseString(string& s1, string& s2,int& idx1,int &idx2){
    int n=s1.size(),m=s2.size(),i=idx1,j=idx2;
    i++,j++;        // because the first characters are anyway same! - i'll need to compare this untill they are either smaller than previous or greater.
    while(i<n && j<m && s1[i]==s2[j]) i++,j++;
    if(i<n && j<m){
        if(s1[i]>s2[j]){
            int original_idx=idx1;
            idx1=i;
            return s1.substr(original_idx,idx1-original_idx);
        }
        else{
            int original_idx=idx2;
            idx2=j;
            return s2.substr(original_idx,idx2-original_idx);    
        }
    }
    if(i==n){
        
        int original_idx=idx2;
        idx2=j;
        return s2.substr(original_idx,idx2-original_idx);    
    }
    
    int original_idx=idx1;
    idx1=i;
    return s1.substr(original_idx,idx1-original_idx);
    
    
}
public:
    string largestMerge(string word1, string word2) {
        //pretty straightforward question the only non trivial part is what to do when the first character in both the words are same
        // in that case we'll need to check which string is greater. 
        int i=0,j=0,n=word1.size(),m=word2.size();
        string smallestString;
        while(i<n && j<m){
            if(word1[i]>word2[j]){
                smallestString.push_back(word1[i++]);
            }
            else if(word1[i]<word2[j]){
                smallestString.push_back(word2[j++]);
            }
            else{
                if(word1.compare(i,word1.size()-i,word2,j,word2.size()-j)>0)
                {
                    
                    smallestString.push_back(word1[i++]);
                }
                else{
                    
                    smallestString.push_back(word2[j++]);
                }
            }
            
        }
        
        if(i<n) smallestString+=word1.substr(i);
        if(j<m) smallestString+=word2.substr(j);
        return smallestString;
        
    }
};
// qqqqqqqqqeqeqqeeqqq"
// qqqqqqqqeqqqeeqqeeqqqqqeq"