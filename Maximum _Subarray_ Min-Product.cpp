class Solution {
public:
#define lli long long int
    
    int findmin(int idx, int cur, vector<int>& minidx, vector<int>& n){  
        if(idx == -1 || idx == n.size())
            return idx;
        if(n[idx] < n[cur])
            return idx;
        
        return findmin(minidx[idx], cur, minidx, n);
            
    }
    int maxSumMinProduct(vector<int>& n){
        
        int sz = n.size();
        lli sum[sz];
        vector<int> left(sz), right(sz);
        
        sum[0] = n[0];
        
        for(int i=1;i<n.size();i++)
            sum[i] = sum[i-1]+n[i];
        
        for(int i=0;i<sz;i++)
            left[i] = findmin(i-1, i, left, n);
        
        for(int i=sz-1;i>=0;i--)
            right[i] = findmin(i+1, i, right, n);
        
        lli gmax = INT_MIN;
        lli res;
        for(int i=0;i<sz;i++){
            res = (sum[right[i]-1] - (left[i]>=0?sum[left[i]]:0)) * n[i];
            gmax = max(gmax,res);
        }
        
        return gmax%1000000007;
    }
};
