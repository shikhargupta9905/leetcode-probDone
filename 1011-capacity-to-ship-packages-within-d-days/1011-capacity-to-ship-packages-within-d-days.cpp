class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int load=0 , day=1;
        for(int i =0; i<weights.size();i++){
            if(load+weights[i]>cap){
                day+=1;
                load= weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        while (high>=low)
        {
            int mid = low+(high-low)/2;
            int noOfDays= findDays(weights, mid);
            if(noOfDays<=days){
                high=mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return low;
    }
};