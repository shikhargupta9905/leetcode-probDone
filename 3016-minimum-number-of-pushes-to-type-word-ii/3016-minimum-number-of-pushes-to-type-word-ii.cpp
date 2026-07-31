class Solution {
public:
    int minimumPushes(string word) {
        vector <int> freq(26,0);
        for (char ch : word ){
            freq[ch-'a']++;
        }
        sort(freq.begin(), freq.end());

        int minPush=0;
        for(int i =25, pushCnt =0;i>=0;i--){
            int currEleIdx=25-i;

            if(currEleIdx %8==0){pushCnt++;}
            minPush+=freq[i]*pushCnt;
        }
        return minPush;
    }
};