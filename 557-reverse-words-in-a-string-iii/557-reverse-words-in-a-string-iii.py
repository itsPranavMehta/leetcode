class Solution:
    def reverseWords(self, s: str) -> str:
        res=""
        for x in s.split(' '): 
            res+=x[::-1]
            res+=" "
        return res[:-1]
        