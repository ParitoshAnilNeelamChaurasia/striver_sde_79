// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;

        sort(nums.begin() , nums.end()) ;

        vector<vector<int>> ans ;

        if(n<3)
        return {} ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue ;
            }

            int j = i+1 ;
            int k = n-1 ;

            int target = -nums[i] ;

            while(j < k)
            {
                int sum = nums[j] + nums[k] ;

                if (sum == target) 
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // Skip duplicates for j and k
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(sum > target)
                {
                    k-- ;
                }
                else
                {
                    j++ ;
                }
            }
        }
        return ans ;
    }
};

// second approach

class Solution {
public:
    vector<vector<int>> result ;

    void twosum(vector<int> &nums , int target , int i , int j)
    {
        while(i < j)
        {
            if(nums[i] + nums[j] == target)
            {
                // first we will remove duplicates from either end (i,j)

                while(i < j && nums[i] == nums[i+1])
                {
                    i++ ;
                }

                while(i < j && nums[j] == nums[j-1])
                {
                    j-- ;
                }

                result.push_back({-target , nums[i] , nums[j]}) ;

                i++ ;
                j-- ;
                 
            }
            else if(nums[i] + nums[j] > target)
            {
                j-- ;
            }
            else
            {
                i++ ;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;

        sort(nums.begin() , nums.end()) ;
        
        if(n < 3)
        {
            return {} ;
        }

        result.clear() ;

        for(int i = 0 ; i < n ; ++i)
        {
            // for not having duplicates
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue ;
            }

            int n1 = nums[i] ;
            int target = -n1 ;

            twosum(nums , target , i+1 , n-1) ;
        }
        return result ;

    }
};
