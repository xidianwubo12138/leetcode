#include<iostream>

class Solution {
public:
    // std::unordered_map<int, int> dpTable;
    // int coinChange(vector<int>& coins, int amount) {
    //     //符合题目要求
    //     if(amount == 0) return 0;
    //     if(amount < 0) return -1;
    //     if(dpTable[amount] != 0) return dpTable[amount];

    //     int res = INT_MAX;
    //     for(auto i: coins) {
    //         int subResult = coinChange(coins, amount - i);
    //         // 解决子问题没结果
    //         if (subResult == -1) continue; 
    //         res = min(res, 1 + subResult);
    //     }
    //     // 防止出现最后问题没结果
    //     dpTable[amount] = (res != INT_MAX)? res: -1;
    //     return dpTable[amount];
    // }
    int coinChange(vector<int>& coins, int amount) {
        //初始化amount+1个值为amount+1的元素
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1 ; i < amount+1; i++){
            for (auto coin: coins){
                // 如果子问题无解
                if(i-coin < 0 || dp[i-coin] == -1){
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
            //如果dp[i]没有发生改变，说明遍历到最后都无解，返回-1
            if (dp[i] == amount + 1){
                dp[i] = -1;
            }
        }
        return dp[amount];
    }

};