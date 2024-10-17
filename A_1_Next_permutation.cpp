// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;

        int gola_ind = -1;

        for(int i = n-1 ; i > 0 ; --i)
        {
            if(nums[i] > nums[i-1])
            {
                gola_ind = i -1 ;
                break ;
            }
        }

        if(gola_ind != -1)
        {
            int swap_ind = -1 ;

            for(int j = n-1 ; j >= gola_ind+1 ; --j)
            {
                // Corrected to find the next larger element
                if(nums[j] > nums[gola_ind])
                {
                    swap_ind = j ;
                    break ;
                }
            }
            swap(nums[swap_ind] , nums[gola_ind]) ;
        }
        reverse(nums.begin() + gola_ind + 1, nums.end()) ;
    }
};
