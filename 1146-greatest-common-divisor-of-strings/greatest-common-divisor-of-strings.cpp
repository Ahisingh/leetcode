class Solution {
public:
    int gcd(int n1, int n2){
        int ans = 1;
        int small = min(n1,n2);
        for(int i=1; i<=small; i++){
            if(n1%i == 0 && n2%i == 0) ans = i;
        }

        return ans;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";

        int range = gcd(str1.size(), str2.size());

        string ans = "";
        for(int i=0; i<range; i++){
            ans += str1[i];
        }

        return ans;
        
    }
};