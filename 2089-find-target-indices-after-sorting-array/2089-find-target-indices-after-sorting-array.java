import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        List<Integer> res = new ArrayList<>();
       
       Arrays.sort(nums);
       for(int i=0 ; i<nums.length;i++){
        if(nums[i]==target){
            res.add(i);
        }
       }
        return res;
        
    }
}