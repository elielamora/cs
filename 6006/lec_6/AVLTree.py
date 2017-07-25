from BinarySearchTree import BinarySearchTree
import random
'''

       (left, middle, right)
             b
        a              d
                   c       e

       (a ,  b  , (c   d   e))

       ===== Equivalent Left Rotation ====
                    d
            b           e
         a     c
       ((a, b, c),  d,  e)


'''
class AVLTree(BinarySearchTree):
    def __init__ (self,
        key = None,
        left = None,
        right = None,
        height = 0
    ):
        super(self.__class__, self).__init__(key, left, right)
        self.__height = height
    def insertLeft(self, key):
        self.setLeft(AVLTree(key))
    def insertRight(self, key):
        self.setRight(AVLTree(key))
    def getHeight(self):
        return self.__height
    def setHeight(self, height):
        self.__height = height
    # balance should equal right.height - left.height
    def balance(self):
        return (self.getRight().height() if
            self.hasRight() else 0) - (self.getLeft().height() if
            self.hasLeft() else 0)
    def rotateRight(self):
        pass
    def rotateLeft(self):
        pass
    '''
    '''
    # def insert(self, key):
    #     #insert
    #     if (self.isEmpty()):
    #         self.setKey(key)
    #     elif (key < self.getKey()):
    #         if (self.hasLeft()):
    #             self.getLeft().insert(key)
    #         else:
    #             self.insertLeft(key)
    #     else: # self.__key <= key
    #         if (self.hasRight()):
    #             self.getRight().insert(key)
    #         else:
    #             self.insertRight(key)
    #     super(self.__class__, self).insert(key)
        #fix avl tree property

    def height(self):
        if (self.isEmpty()):
            return 0
        if (self.isLeaf()):
            return 1
        return 1 + max(
            self.getLeft().height() if self.hasLeft() else 0,
            self.getRight().height() if self.hasRight() else 0
        )
    def display(self, level = 0):
        indent = (" " * 4)
        nl = "\n"
        none = "nil"
        s = ((indent * level) + str(self.getKey()) + ":" +
            str(self.balance()) +
            nl)
        if self.hasLeft():
            s = s + self.getLeft().display(level + 1)
        else:
            s = s + indent  * (level + 1) + none + nl
        if self.hasRight():
            s = s + self.getRight().display(level + 1)
        else:
            s = s + indent  * (level + 1) + none + nl
        return s





'''
TEST
'''
def main():
    # test insert, sort and diplay
    items = 15
    r = 25
    tree = AVLTree(0)
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
    # testing height
    print "testing height"
    print "height of tree is " + str(tree.height())

if __name__ == "__main__":
    main()
