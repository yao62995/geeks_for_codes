#!/usr/bin/env python
# -*- coding: utf-8 -*-
# author: yao62995<yao_62995@163.com>

from generator import TreeGenerator
import tree_algo

tg = TreeGenerator(max_depth=4)


def generate_trees(num=1, _print=False):
    trees = [tg.generate_binary_tree() for _ in xrange(num)]
    if _print:
        for i, tree in enumerate(trees):
            print "==tree%d\n" % i, tg.print_tree(tree)
    return trees


def test_determine_if_two_trees_are_identical():
    solution = tree_algo.determine_if_two_trees_are_identical.Solution()
    tree1, tree2 = generate_trees(num=2)
    print "is identical:", solution.determine_if_two_trees_are_identical(tree1, tree2)
