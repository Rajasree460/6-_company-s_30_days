class Solution {
    void solve(int num,int sum,int n,int k,vector<vector<int>>&mt,vector<int>&arr){
    if(sum>n) return;

    if(k==0){
        if(sum==n){
            mt.push_back(arr);
            return;
        }
        return;
    }
    if(num==10) return;
    arr.push_back(num);
    sum+=num;
    solve(num+1,sum,n,k-1,mt,arr);
    sum-=num;
    arr.pop_back();
    solve(num+1,sum,n,k,mt,arr); 
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>mt;
        vector<int>arr;
        solve(1,0,n,k,mt,arr);
        return mt;
    }
};
