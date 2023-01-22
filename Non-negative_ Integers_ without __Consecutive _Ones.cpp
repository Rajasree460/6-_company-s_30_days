class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int res = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num&(1<<k)) {
                res += f[k];
                if (pre_bit) return res;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return res+1;
    }
};
