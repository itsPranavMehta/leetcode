class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k%=nums.size();

        int count=0;
        for(int i=0;count<nums.size();i++)
        {
            int curr=i;
            int prev=nums[i];
            do{
                int next=(curr+k)%nums.size();
                int temp=nums[next];
                nums[next]=prev;
                prev=temp;
                curr=next;
                count++;
            }while(i!=curr);     //so that it executes and doesn't get's stuck on first iteration itself
        }
    }
};