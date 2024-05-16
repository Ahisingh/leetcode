class Solution {
public:
    bool isPalindrome(int x){
        long long rev=0;
        long long temp = x;
        if(temp<0){
            return false;
        }
        while(temp!=0)
        {
            rev=rev*10+temp%10;
            temp=temp/10;
        }
        return x == rev;
    }
};