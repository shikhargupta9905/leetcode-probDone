class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;\

        double logRes= log10(n)/log10(3);

        return fmod(logRes,1)==0;
    }
};