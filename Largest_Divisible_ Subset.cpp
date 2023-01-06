class Solution {
public:
     // Globally Declearization
    vector<int> ans;
    void helper(int i,vector<int>& nums,vector<int>& vec,vector<int>& dp){
        // Base Case
        // IBH(Induction, Base & Hypothetically)
        int n=nums.size();
        if(i==n){
            if(vec.size()>ans.size())
            ans=vec;
            return;
        }
        if(vec.size()==0){
            vec.push_back(nums[i]);
            helper(i+1,nums,vec,dp); // Recursive Calling
            vec.pop_back(); // Backtracking
        }
        else if((int)vec.size()>dp[i] && nums[i]%vec.back()==0){
            dp[i]=vec.size();
            vec.push_back(nums[i]);
            helper(i+1,nums,vec,dp);   // Recursive calling
            vec.pop_back();  // Backtracking
        }
        helper(i+1,nums,vec,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> vec;
        vector<int> dp(nums.size()+1,-1);
        sort(nums.begin(),nums.end());
        helper(0,nums,vec,dp);
        return ans;
    }
};
