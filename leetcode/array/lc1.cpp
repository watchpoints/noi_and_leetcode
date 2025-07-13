//https://leetcode.cn/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @微信公共号: 后端开发成长指南
// @微信: watchpoints
class Solution {
public:
    //两数之和
    vector<pair<int,int>> twoALLSum(vector<int>& nums, int target) 
    {   //定义数据结构
        vector<pair<int,int>> output; 
        //返回值 可能匹配多个
        //nums:[1, 2, 3, 4, 5, 6]	target:6	outout:[[0, 4], [1, 3]]
        unordered_map<int,vector<int>> key_map;
        //key:nums[i],value:i
        //inut:[2, 2, 2]	target=4	[[0, 1], [0, 2], [1, 2]]
        //[i,j] j no exites ,no return j>i,return [i,j]
        
        // o(n)
        for(int i = 0 ;i < nums.size(); i++)
        {
            auto index_iter = key_map.find(target-nums[i]);
            //find the number
            if (index_iter != key_map.end()) {
                for(auto index = index_iter->second.begin();index != index_iter->second.end();index++){
                    output.push_back(make_pair(*index,i));
                    //return [i,j] i<j
                }
            }
            key_map[nums[i]].push_back(i);
            //如果 nums[i] 这个 key 不存在于 key_map，则 key_map[nums[i]]
            //会自动创建一个空的 vector<int>，然后再 push_back(i)。
        }

        return output;
    }

    vector<int> twoSum(vector<int>& nums, int target) 
    {
         vector<int> outout;
         auto result = twoALLSum(nums,target);
         outout.push_back(result[0].first);
         outout.push_back(result[0].second);
         return outout;
    }
};
int main()
{
    Solution test;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int target = 6;
    auto res = test.twoALLSum(nums, target);
    for (auto &p : res) {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << endl;
    return 0;
}