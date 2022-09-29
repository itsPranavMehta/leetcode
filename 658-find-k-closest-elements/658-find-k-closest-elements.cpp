class Solution {
private:
    int ClosestElementIndex(vector<int>& arr,int x){
        int min_distance=INT_MAX,index=-1;
        for(int i=0;i<arr.size();i++){
            if(abs(arr[i]-x)<min_distance){
                min_distance=abs(arr[i]-x);
                index=i;
            }
        }
        return index;
        
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int center=ClosestElementIndex(arr,x);
        int i=center-1,j=center+1;
        while(i>=0 && j<n && --k>0){
            if(abs(arr[i]-x)<=abs(arr[j]-x))    i--;
            else j++;
              
        }
        
        while(i>=0 && --k>0)  i--;
        while(j<n && --k>0) j++;
        
        return vector<int>(arr.begin()+(i+1),arr.begin()+j);
        
    }
};