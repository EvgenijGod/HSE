import sys


class Node:
    def __init__(self, val):
        self.value = val
        self.leftChild = None
        self.rightChild = None

    def insert(self, data):
        if self.value != data:
            if self.value > data:
                if self.leftChild:
                    return self.leftChild.insert(data)
                else:
                    self.leftChild = Node(data)
            else:
                if self.rightChild:
                    return self.rightChild.insert(data)
                else:
                    self.rightChild = Node(data)

    def height(self):
        if self.leftChild and self.rightChild:
            return 1 + max(self.leftChild.height(), self.rightChild.height())
        elif self.leftChild:
            return 1 + self.leftChild.height()
        elif self.rightChild:
            return 1 + self.rightChild.height()
        else:
            return 1

    def isBalanced(self):
        if not self.leftChild:
            if not self.rightChild:
                return True
            elif self.rightChild.height() == 1:
                return True
            else:
                return False
        elif not self.rightChild:
            if self.leftChild.height() == 1:
                return True
            else:
                return False
        elif abs(self.leftChild.height() - self.rightChild.height()) > 1:
            return False
        else:
            if self.leftChild:
                if self.rightChild:
                    return self.leftChild.isBalanced() \
                           and self.rightChild.isBalanced()
                else:
                    return self.leftChild.isBalanced()
            elif self.rightChild:
                return self.rightChild.isBalanced()
        return True


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root:
            return self.root.insert(data)
        else:
            self.root = Node(data)
            return True

    def height(self):
        if self.root:
            return self.root.height()
        else:
            return 0

    def isBalanced(self):
        if self.root:
            return self.root.isBalanced()

    def printTree(self):
        if self.root:
            self._printTree(self.root)

    def _printTree(self, curNode):
        if curNode:
            self._printTree(curNode.leftChild)
            print(curNode.value)
            self._printTree(curNode.rightChild)


def fillTree(tree):
    l = list(map(int, sys.stdin.readline().split()))
    for el in l:
        if el != 0:
            tree.insert(el)


def main():
    bst = Tree()
    fillTree(bst)
    if bst.isBalanced():
        print('YES')
    else:
        print('NO')


main()
