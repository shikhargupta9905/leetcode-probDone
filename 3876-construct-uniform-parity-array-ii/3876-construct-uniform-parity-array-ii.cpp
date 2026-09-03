class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int>num2;
        int i = 0 ;
        int min_val = nums1[0];  // odd or even 
        bool has_odd= false;
        
        for(int x : nums1){
            if(x<min_val){
                min_val=x;
            }
            if(x%2!=0){
                has_odd = true;
            }
        }
        if(!has_odd) return true;
        if (min_val % 2 != 0) return true;

        return false;
            
        
    }
};