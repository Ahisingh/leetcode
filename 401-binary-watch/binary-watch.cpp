const int TOTAL_HOURS_AM_PM_MODE_PER_DAY = 12;
const int TOTAL_MINUTES_PER_HOUR = 60;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn);
};
/************************************************************************/
vector<string> Solution::readBinaryWatch(int turnedOn) {
    vector<string> v;
    if (turnedOn > 10) {
        return v;
    }
    int h, min;
    bitset<4> bH;
    bitset<6> bMin;
    char hC[4], minC[3];
    string s;
    for (h = 0; h < TOTAL_HOURS_AM_PM_MODE_PER_DAY; ++h) {
        for (min = 0; min < TOTAL_MINUTES_PER_HOUR; ++min) {
            bH = h;
            bMin = min;
            if (bH.count() + bMin.count() == turnedOn) {
                sprintf(hC,"%d:",h);
                sprintf(minC,"%02d", min);
                s="";
                s+=hC;
                s+=minC;
                v.emplace_back(s);
            }
        } 
    }
    return v;
}
/************************************************************************/