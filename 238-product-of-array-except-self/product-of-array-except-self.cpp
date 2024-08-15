class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        long long int product = 1;
        int n = nums.size();
        int count_of_zero = 0;
        for(int i=0; i<n; i++){

            if(nums[i] == 0){
                count_of_zero ++;
            }else{
                product = product * nums[i];
            }
        }

        for(int i=0; i<n; i++){

            if(count_of_zero >= 2){
                nums[i] = 0;
            }else if(count_of_zero == 1){
                if(nums[i] !=0){
                    nums[i] = 0;
                }else{
                    nums[i] = product;
                }
            }else{
                nums[i] = product / nums[i];
            }

        }

        return nums;
    }
};