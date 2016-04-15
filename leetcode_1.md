#1. Two Sum My Submissions QuestionEditorial Solution
Total Accepted: 217311 Total Submissions: 954222 Difficulty: Easy
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

`C ++ code` 
``` c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for( int i=0; i < nums.size(); ++ i ){
            for( int j=i+1; j < nums.size(); ++ j ){
                if( nums[i] + nums[j] == target ){
                    ans.push_back( i );
                    ans.push_back( j );
                    break;
                }
            }
        }

        return ans;
    }
};
```

It is easy that finding a + b in integer array nums is equal to target!
