#!/usr/bin/env python
# -*- coding: utf-8 -*-
# author: yao62995<yao_62995@163.com>

"""
Two trees are identical when they have same data and arrangement of data is also same.
"""


class Solution(object):
    def determine_if_two_trees_are_identical(self, tree1, tree2):
        if tree1 is None and tree2 is None:
            return True
        if type(tree1) != type(tree2) \
                or tree1.val != tree2.val \
                or not self.determine_if_two_trees_are_identical(tree1.left, tree2.left) \
                or not self.determine_if_two_trees_are_identical(tree1.left, tree2.left):
            return False
        return True
