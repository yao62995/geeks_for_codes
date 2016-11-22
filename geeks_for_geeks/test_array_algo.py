#!/usr/bin/env python
# -*- coding: utf-8 -*-
# author: yao62995<yao_62995@163.com>

from generator import ListGenerator, LinkedListGenerator
import array_algo

lg = ListGenerator()
llg = LinkedListGenerator()


def generate_list(num=1, _print=False):
    list_set = [lg.generate_list() for _ in xrange(num)]
    if _print:
        for i, seq_list in enumerate(list_set):
            print "==list%d\n\t" % i, seq_list
    return list_set


def generate_linked_list(num=1, _print=False):
    linked_list_set = [llg.generate_linked_list() for _ in xrange(num)]
    if _print:
        for i, linked_list in enumerate(linked_list_set):
            print "==link_list%d\n\t" % i, llg.print_tree(linked_list)
    return linked_list_set
