class Solution {
    private:
    
    pair<int,int> calculateSlope(int y2, int y1, int x2,int x1){
        int g =__gcd(abs(y2-y1),abs(x2-x1));
        return {(y2-y1)/g,(x2-x1)/g};
    }
    
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size()<2)    return 0;
        // basic geometry required here-> slope of a line between 2 points is (y2-y1)/(x2-x1), if this slope continues then well and good! else new line required;
        // but storing decimal values is another problem so will have to store it in order -> x2-x1 and y2-y1 both divided by their gcd
        
        sort(stockPrices.begin(),stockPrices.end());
        pair<int,int> slope=calculateSlope(stockPrices[1][1],stockPrices[0][1],stockPrices[1][0],stockPrices[0][0]);
        
        int numLines=1;
        for(int idx=2;idx<stockPrices.size();idx++){
            pair<int,int> currentSlope=calculateSlope(stockPrices[idx][1],stockPrices[idx-1][1],stockPrices[idx][0],stockPrices[idx-1][0]);
        
            if(currentSlope!=slope){
                numLines++;
                slope=currentSlope;
            }
        }
        
        return numLines;
    }
};