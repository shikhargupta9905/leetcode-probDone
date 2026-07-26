class Solution {
public:
bool canWePlace(vector<int>& position, int dist, int balls){
    int cntBall=1,last = position[0];
    for(int i =0;i<position.size();i++){
        if(position[i]-last>=dist){
            cntBall+=1;
            last=position[i];
        }
        if(cntBall>=balls) return true;
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low =0, high = position[n-1];
        while (low<= high){
            int mid = low+(high-low)/2;
            if(canWePlace(position , mid , m)==true){
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};