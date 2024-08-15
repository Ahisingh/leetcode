class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int lemon5=0,lemon10=0;
        for(int i:bills){
            if(i==5)
                lemon5++;
            else if(i==10){
                if(lemon5>0){
                    lemon5--;
                    lemon10++;
                }
                else
                    return false;
            }
            else{
                if(lemon5>2 || (lemon10>0 && lemon5>0) ){
                    if(lemon10){
                        lemon10--;
                        lemon5--;
                    }
                    else
                        lemon5-=3;
                }
                else
                    return false;
            }
        }

        return true;
    }
};