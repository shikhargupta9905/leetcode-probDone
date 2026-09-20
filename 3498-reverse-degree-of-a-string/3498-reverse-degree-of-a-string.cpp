class Solution {
public:
    int reverseDegree(string s) {
        int sum =0;
        int n = s.size();
        int i =0;
        int x=1;
        while(n>0){
            int k = (26-(s[i]-'a') )*x;
            sum+=k;
            i++;
            x++;
            n--;
        }
        return sum;
    }
};