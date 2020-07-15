# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

mn = []
mx = []

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        mn.clear()
        mx.clear()
        self.dfs(root, 0, 0)
        return max(r - l + 1 for l, r in zip(mn, mx))

    def dfs(self, cur: TreeNode, lvl: int, row: int) -> None:
        if cur is None:
            return
        if lvl == len(mn):
            mn.append(row)
            mx.append(row)
        else:
            mx[lvl] = row
        lvl += 1
        row *= 2
        self.dfs(cur.left , lvl, row)
        row += 1
        self.dfs(cur.right, lvl, row)
