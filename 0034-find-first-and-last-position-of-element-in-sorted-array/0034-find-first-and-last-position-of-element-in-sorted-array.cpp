class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int fidx = -1;
        int lidx = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target){
                if(mid > 0 && nums[mid-1] == nums[mid]) hi = mid - 1;
                else {
                    fidx = mid;
                    break;
                }
            }
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
         if (fidx == -1) return {-1, -1};
         lo = 0;
         hi = nums.size() - 1;
         while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target){
                if(mid < nums.size()-1 && nums[mid+1] == nums[mid]) lo = mid + 1;
                else {
                    lidx = mid;
                    break;
                }
            }
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return {fidx, lidx};
    }
};