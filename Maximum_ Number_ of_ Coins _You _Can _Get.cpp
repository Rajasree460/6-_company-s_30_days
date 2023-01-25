class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int sum = 0;
        sort(piles.begin(),piles.end(),greater<int>());
        
        for(int i=1;i<=(piles.size()/3)*2;i+=2)
        {
            sum+=piles[i];
        }
        return sum;
        
    }
};
