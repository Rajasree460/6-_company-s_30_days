#define ll long long
class Solution {
    bool helper(int &x){
        int num=x;
       ll res=0;
       while(x>0){
           //int digit=x%10;
           res=res*10+x%10; //res=digit+res*10;
           x/=10;   //x=x/10;
       }
       if(res==num) return true;
       else return false;
       //return  res==num?1:0;
    }
public:
    bool isPalindrome(int x) {
       return helper(x);
       
    }
};
