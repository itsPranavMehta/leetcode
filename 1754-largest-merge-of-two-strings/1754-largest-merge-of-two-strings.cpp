class Solution {
public:
    string largestMerge(string word1, string word2) {
        //pretty straightforward question the only non trivial part is what to do when the first character in both the words are same
        // in that case we'll need to check which string is greater. 
        int i=0,j=0,n=word1.size(),m=word2.size();
        string smallestString;
        while(i<n && j<m){
            // if(word1.compare(i,word1.size()-i,word2,j,word2.size()-j)>0){
            if(word1.substr(i)>word2.substr(j)){
                smallestString.push_back(word1[i++]);
            }
            else{
                smallestString.push_back(word2[j++]);
            }
        }
        
        if(i<n) smallestString+=word1.substr(i);
        if(j<m) smallestString+=word2.substr(j);
        return smallestString;
        
    }
};