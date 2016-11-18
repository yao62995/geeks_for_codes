#!/usr/bin/env python
# -*- coding: utf-8 -*-
# author: yao62995<yao_62995@163.com>

import random


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


# Definition for binary tree node.
class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Generator(object):
    def __init__(self, _range=(1, 100), alpha=0.95):
        self.range = _range
        self.alpha = alpha


class ListGenerator(Generator):
    def __init__(self, _range=(1, 100), alpha=0.95, max_length=100):
        Generator.__init__(self, _range=_range, alpha=alpha)
        self.max_length = max_length

    def generate_list(self):
        seq_list = []
        while len(seq_list) < self.max_length and random.random() > self.alpha:
            val = random.randint(self.range[0], self.range[1])
            seq_list.append(val)
        return seq_list

    def generate_distinct_list(self):
        pass


class LinkedListGenerator(Generator):
    def __init__(self, _range=(1, 100), alpha=0.95, max_length=100):
        Generator.__init__(self, _range=_range, alpha=alpha)
        self.max_length = max_length

    def generate_linked_list(self):
        linked_list = None
        list_size = 0
        while list_size < self.max_length and random.random() > self.alpha:
            val = random.randint(self.range[0], self.range[1])
            elem = ListNode(val)
            if linked_list is None:
                linked_list = elem
            else:
                elem.next = linked_list.next
                linked_list.next = elem.next
        return linked_list

    def print_linked_list(self, linked_list):
        ptr = linked_list
        while ptr:
            print ptr.val, "=>",
            ptr = ptr.next
        print "NULL"


class TreeGenerator(Generator):
    def __init__(self, _range=(1, 100), alpha=0.9, max_depth=10):
        Generator.__init__(self, _range=_range, alpha=alpha)
        # max depth
        self.max_depth = max_depth

    def generate_binary_tree(self, depth=1):
        if depth > self.max_depth or random.random() > self.alpha:
            return None
        else:
            val = random.randint(self.range[0], self.range[1])
            node = TreeNode(val)
            node.left = self.generate_binary_tree(depth=depth + 1)
            node.right = self.generate_binary_tree(depth=depth + 1)
            return node

    def print_tree(self, btree, depth=1):
        if btree:
            print "[%s]" % depth, "--" * depth, str(btree.val).rjust(3)
            self.print_tree(btree.left, depth=depth + 1)
            self.print_tree(btree.left, depth=depth + 1)


if __name__ == "__main__":
    tg = TreeGenerator()
    root = tg.generate_binary_tree()
    tg.print_tree(root)
