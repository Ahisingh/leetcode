class Solution {
public:
    string intToRoman(int num) {
        // Define a map to store integer to Roman numeral mappings
        map<int, string> values = 
        {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},
         {40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
         {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        
        string res; // Initialize the result string

        // Use reverse iterator to iterate through the map from largest to smallest value
        map<int, string>::reverse_iterator it;
        for (it = values.rbegin(); it != values.rend(); it++){
            // While the current value can be subtracted from num
            while(num >= it->first){
                res += it->second; // Append the Roman numeral to result
                num -= it->first;  // Subtract the value from num
            }
        }
        return res; // Return the final Roman numeral representation
    }
};
