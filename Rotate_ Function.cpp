class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    int n=nums.size();
     int sum=0;
     long original=0;
     for(int i=0;i<n;i++)
     {
         sum+=nums[i];
         original+=i*nums[i];
     }   
     long Max=original;
    
     for(int i=n-1;i>=0;i--){
         original+=sum-(nums[i]*n);
         Max=max(original,Max);
     }
     return Max;
    }
    
};
