class Solution {
public:
    string longestPrefix(string s) {
        //Using KMP Algorithm
        //Length of String
        int n=s.size();
        //Creating for the Holding the value of Prefix and Suffix
        vector<int>lps(n,0);
        int i=1,j=0;
        while(i<n){
            if(s[i]==s[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else if(j>0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
        int SamePrefixSuffix=lps[n-1];
        return s.substr(0,SamePrefixSuffix);
    }
};
