#
from BinaryTree import BinaryTree
import random


class BinarySearchTree (BinaryTree):
    def insertLeft(self, key):
        self.setLeft(BinarySearchTree(key))
    def insertRight(self, key):
        self.setRight(BinarySearchTree(key))
    def insert(self, key):
        if (self.isEmpty()):
            self.setKey(key)
        elif (key < self.getKey()):
            if (self.hasLeft()):
                self.getLeft().insert(key)
            else:
                self.insertLeft(key)
        else: # self.__key <= key
            if (self.hasRight()):
                self.getRight().insert(key)
            else:
                self.insertRight(key)
    def min(self):
        if (self.isEmpty()):
            return None
        if (self.hasLeft()):
            return self.getLeft().min()
        else:
            return self
    def max(self):
        if (self.isEmpty()):
            return None
        if (self.hasRight()):
            return self.getRight().max()
        else:
            return self
    def delete(self):
        # if (key is not None):
        #     found = self.find(key)
        #     if found is not None:
        #         found.delete()
        #     else:
        #         return None
        # else:
        if self.isLeaf() : # deletes self
            self.setKey(None)
        elif self.hasLeft() and (not self.hasRight()) :
            left = self.getLeft()
            self.setKey(left.getKey())
            self.setLeft(left.getLeft())
            self.setRight(left.setRight())
        elif (self.hasRight() and (not self.hasLeft()) ):
            right = self.getRight()
            self.setKey(right.getKey())
            self.setLeft(right.getLeft())
            self.setRight(right.getRight())
        elif self.hasLeft() and self.hasRight() :
            #switch with min on right side # max of left would work too
            m = self.getRight().min()
            self.setKey(m.getKey())
            m.delete()


    '''
    returns tree with @key
    '''
    def find(self, key):
        if (self.getKey() == key):
            return self
        else:
            if (key < self.getKey() and self.hasLeft()):
                return self.getLeft().find(key)
            elif (self.getKey() <= key and self.hasRight()):
                return self.getRight().find(key)
            else:
                return None

    def sorted(self, sorted = []):
        if (self.hasLeft()):
            self.getLeft().sorted(sorted)
        sorted.append(self.getKey())
        if (self.hasRight()):
            self.getRight().sorted(sorted)
        return sorted








### Test
def main():
    # test insert, sort and diplay
    items = 15
    r = 25
    tree = BinarySearchTree(0)
    for i in range(0, items):
        randint = random.randint(-r,r)
        print randint
        tree.insert(randint)

    print tree.display()
    sorted = tree.sorted()
    print sorted
    # test min and max
    print "min is " + str(tree.min().getKey())
    print "max is " + str(tree.max().getKey())
    # test find
    f = random.choice(sorted)
    print "find " + str(f) + " in tree then print it"
    found = tree.find(f)
    if found != None:
        print found.display()
    else:
        print str(f) + " was not found."
    # test delete
    print "delete " + str(f)
    if found != None:
        found.delete()
        print tree.display()
        print tree.sorted([])

if __name__ == "__main__":
    main()
