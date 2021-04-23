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


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root:
            return self.root.insert(data)
        else:
            self.root = Node(data)
            return True

    def getHeight(self):
        if self.root:
            return self.root.height()
        else:
            return 0

    def printBranchTree(self):
        if self.root:
            self._printBranchTree(self.root)

    def _printBranchTree(self, curNode):
        if curNode:
            self._printBranchTree(curNode.leftChild)
            if (curNode.rightChild and not curNode.leftChild) \
                    or (curNode.leftChild and not curNode.rightChild):
                print(curNode.value)
            self._printBranchTree(curNode.rightChild)


def fillTree(tree):
    l = list(map(int, sys.stdin.readline().split()))
    for el in l:
        if el != 0:
            tree.insert(el)


def main():
    bst = Tree()
    fillTree(bst)
    bst.printBranchTree()


main()
