/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n;
        while(l<=r){
            long mid=(1ll+l+r)/2;
            int comp=guess(mid);
            if(comp==0) return mid;
            if(comp==-1){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};