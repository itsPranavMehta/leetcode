class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int nothingInHand[n+1][k+1],stockBought[n+1][k+1];
        memset(nothingInHand,0,sizeof nothingInHand);
        memset(stockBought,0,sizeof stockBought); 
        for(int i=0;i<=k;i++)   stockBought[0][i]=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=k;j++)
            {
                nothingInHand[i][j]=max(nothingInHand[i-1][j],stockBought[i-1][j]+prices[i-1]);
                stockBought[i][j]=max(stockBought[i-1][j],nothingInHand[i-1][j-1]-prices[i-1]);
                
            }
        }
        
        return *max_element(nothingInHand[n],nothingInHand[n]+k+1);
        
    }
};