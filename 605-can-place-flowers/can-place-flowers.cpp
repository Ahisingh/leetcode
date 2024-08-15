class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        if(n == 0) return true; // e (size 0)
        if(flowerbed.size() == 1){ // e (size 1)
            if(flowerbed[0] == 1) return false;
            else return true;
        }
        for(int i = 0;i < s;i++){   
            if((i > 0 && i < s - 1 && flowerbed[i - 1] == 0 
            && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            || (i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) // e (checking for 0 index)
            || (i == s - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0)){ // e (checking for size - 1 index)
                 n--;
                 flowerbed[i] = 1;
                 }
        }
        return n <= 0;
    }
};