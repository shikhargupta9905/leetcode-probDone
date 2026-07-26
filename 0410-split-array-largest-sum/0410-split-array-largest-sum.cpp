class Solution {
public:
int noOfStudent(vector<int>& nums,int k){
     int load=0 , students=1;
        for(int i =0; i<nums.size();i++){
            if(load+nums[i]<=k){
               
                load+= nums[i];
            }
            else{
                students+=1;
                load =nums[i];
            }
        }
        return students;
}
    int splitArray(vector<int>& nums, int k) {
       int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);
        while (high>=low)
        {
            int mid = low+(high-low)/2;
            int students= noOfStudent(nums, mid);
            if(students<=k){
                high=mid-1;
            }
            else{
                low= mid+1;
            }
        } 
        return low;
    }
};

// class Solution {
// public:
//     int findDays(vector<int>& weights, int cap){
//         int load=0 , day=1;
//         for(int i =0; i<weights.size();i++){
//             if(load+weights[i]>cap){
//                 day+=1;
//                 load= weights[i];
//             }
//             else{
//                 load+=weights[i];
//             }
//         }
//         return day;
//     }

//     int shipWithinDays(vector<int>& weights, int days) {
//         int low = *max_element(weights.begin(), weights.end());
//         int high = accumulate(weights.begin(), weights.end(),0);
//         while (high>=low)
//         {
//             int mid = low+(high-low)/2;
//             int noOfDays= findDays(weights, mid);
//             if(noOfDays<=days){
//                 high=mid-1;
//             }
//             else{
//                 low= mid+1;
//             }
//         }
//         return low;
//     }
// };