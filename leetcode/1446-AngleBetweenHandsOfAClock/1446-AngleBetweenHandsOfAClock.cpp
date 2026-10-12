// Last updated: 10/12/2026, 9:52:26 PM
class Solution {
public:
    double angleClock(int h, int m) {
        double x = h + m / 60.0;
        double diff = fmod(11.0 * x , 12.0);
        return min(diff,12.0-diff)* 30.0;
    }
};