class Solution {
public:
    bool prime(int n){
        if(n<=1){
            return false;
        }
        int sq = sqrt(n);
        for(int i = 2;i<=sq;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int nonSpecialCount(int l, int r) {
        int ans=0;
        for(int i=ceil(sqrt(l));i<=floor(sqrt(r));i++){
            if(prime(i)){
                ans++;
            }
        }
        return (r-l+1)-ans;
    }
};