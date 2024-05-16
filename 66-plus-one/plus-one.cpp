class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size() - 1;
        
         while(end>=0)
        {
            if(digits[end]==9)
            {
                digits[end] = 0;
            }
            else{
                digits[end]+=1;
                return digits;
            }

            end--;
        }

      digits.insert(digits.begin(),1);
      return digits;
    }
};