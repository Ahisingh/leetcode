class Solution {
public:
    int maxProduct(vector<int>& n) {
        int pre=1,suf=1,maxp=INT_MIN,i,l=n.size(),p=1;
        for(i=0;i<l;i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            pre*=n[i];
            suf*=n[l-i-1];
            maxp=max(maxp,max(pre,suf));
        }
        return maxp;
    }
};