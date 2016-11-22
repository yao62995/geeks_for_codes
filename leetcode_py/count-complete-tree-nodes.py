class Solution(object):
    def __init__(self):
        self.max_depth = 0
        self.counter = 0

    def _countNodes(self, node, depth):
        if not node.left and not node.right:
            if self.max_depth is None:
                self.max_depth = depth
            if depth == self.max_depth:
                self.counter += 1
                return False
            else:
                return True
        if node.left:
            if self._countNodes(node.left, depth + 1):
                return True
        if node.right:
            if self._countNodes(node.right, depth + 1):
                return True
        return False

    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        self.max_depth = None
        self.counter = 0
        self._countNodes(root, 1)
        node_num = pow(2, self.max_depth - 1) - 1 + self.counter
        return node_num