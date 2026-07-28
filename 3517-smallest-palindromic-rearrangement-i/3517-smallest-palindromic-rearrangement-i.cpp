class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int halfLen = n/2;
        string half= s.substr(0,halfLen);
        sort(half.begin(),half.end());
        string mid= (n%2!=0)?string(1,s[halfLen]):"";
        string revHalf = half;
        reverse(revHalf.begin(), revHalf.end());

        return half + mid + revHalf;

        
    }
};