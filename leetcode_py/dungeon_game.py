#!/usr/bin/env python
# -*- coding: utf-8 -*-
# author: yao62995<yao_62995@163.com>

"""
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
The dungeon consists of M x N rooms laid out in a 2D grid.
Our valiant knight (K) was initially positioned in the top-left room

The knight has an initial health point represented by a positive integer.
If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible,
the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below,
the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2(K)	-3	 3
-5	   -10	  1
10   	30	 -5(P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room
where the princess is imprisoned.
"""


class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        row_num, col_num = len(dungeon), len(dungeon[0])
        dp = [[0] * col_num for _ in xrange(row_num)]
        for row in xrange(row_num - 1, -1, -1):
            for col in xrange(col_num - 1, -1, -1):
                if row == (row_num - 1) and col == (col_num - 1):
                    dp[row][col] = max(1, 1 - dungeon[row][col])
                else:
                    if row == (row_num - 1):
                        min_out = dp[row][col + 1]
                    elif col == (col_num - 1):
                        min_out = dp[row + 1][col]
                    else:
                        min_out = min(dp[row + 1][col], dp[row][col + 1])
                    dp[row][col] = max(1, min_out - dungeon[row][col])
        return dp[0][0]

s = Solution()
print s.calculateMinimumHP([[-2, -3, 3], [-5, -10, 1], [10, 30, -5]])


