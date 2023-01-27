class Solution {
public:
    
    // lets assume that ant left[i] and right[i] collide at any point x;
    // so after collision they change their direction
    
    // so after collision ant left[i] change its direction and start moving towards right from point x
    // after collision ant right[j] change its direction and start moving towards left from point x
    
    // now we can replace left[i] and right[j] ant -> and there will be no effect of collision
    
    //so after collision rather than changing their direction assume left[i] becomes right[j] and vice versa
    
    
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int ans=0;
        for(int i=0;i<left.size();i++){
            ans=max(ans,(abs(0-left[i])));
        }
        
        for(int i=0;i<right.size();i++){
            ans=max(ans,abs(n-right[i]));
        }
        
        return ans;
    }
};
