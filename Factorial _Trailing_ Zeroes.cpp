class Solution {
public:
    int trailingZeroes(int n) {
        int ct=0;
        while(n){
            n/=5;
            ct+=n;
        }
        return ct;
    }
};
