class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        unordered_set<string>st;
        for(int len=1;len<=n/2;len++){
            int count =0;class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        unordered_set<string>st;
        for(int len=1;len<=n/2;len++){
            int count =0;
            for(int left=0,right=len;right<n;right++,left++){
                if(text[left]==text[right])count++;
                else count=0;

                if(count==len){
                    string str = text.substr(left,right-left+1);
                    st.insert(str);
                    count--;
                }
            }
        }
        return st.size();
    }
};
            for(int left=0,right=len;right<n;right++,left++){
                if(text[left]==text[right])count++;
                else count=0;

                if(count==len){
                    string str = text.substr(left,right-left+1);
                    st.insert(str);
                    count--;
                }
            }
        }
        return st.size();
    }
};
