class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0; // as the left pointer
        int j=0; // as the right pointer
        int res=0;
        vector<int>n(3,0); // a,b,c initialized from 0
        for(j=0;j<s.length();j++){
            n[s[j]-'a']++; // we will increament the count of the respect two char of the right pointer
            while(n[0]>0 && n[1]>0 && n[2]>0 && i<=j){ // when (a,b,c)>0 && left pointer <= right pointer
                n[s[i]-'a']--; // decrement the count of the letter at the left pointer 
                res+=(s.length()-j); // include letters from the right pointer to the last: that much substring will be included in the res
                i++; // increment till there are sufficient a,b,c b/w left and right pointer that are > 0
            }
        }
        return res;
    }
};
