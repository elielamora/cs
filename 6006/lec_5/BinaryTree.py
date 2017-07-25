# Eliel
# Binary Tree ADT
#


class BinaryTree (object):
    '''
        Parentless, orderless, minimalist Binary Tree
              t(key)
            /        \
        l(key)      r(key)
        # todo: throw errors if left || right are set to
        # non-BinaryTree objects
    '''
    def __init__ (self, key = None, left = None, right = None):
        self.__key = key
        self.__left = left
        self.__right = right
    def getLeft(self):
        return self.__left
    def getRight(self):
        return self.__right
    def setLeft(self, left = None):
        self.__left = left
    def setRight(self, right = None):
        self.__right = right
    def setKey(self, key = None):
        self.__key = key
    def getKey(self):
        return self.__key
    def insertLeft(self, key):
        self.setLeft( BinaryTree(key) )
    def insertRight(self, key):
        self.setRight( BinaryTree(key) )
    def isEmpty(self):
        return self.getKey() == None
    def hasLeft(self):
        left = self.getLeft()
        if left == None:
            return False
        else:
            if left.isEmpty():
                return False
            else:
                return True
    def hasRight(self):
        right = self.getRight()
        if right == None:
            return False
        else:
            if right.isEmpty():
                return False
            else:
                return True
    def isLeaf(self):
        return (not self.hasLeft()) and (not self.hasRight())
    #abstract ADT
    def insert(self, key):
        pass
    def delete(self, key):
        pass
    def find(self, key):
        pass
    def min(self):
        pass
    def max(self):
        pass
    def removeLeft(self):
        l = self.__left
        self.__left = None
        return l
    def removeRight(self):
        r = self.__right
        self.__right = None
        return r
    def __repr__(self):
        return self.__dict__ + " super: " + super
    def __str__(self):
        return self.display()
    def display(self, level = 0):
        indent = (" " * 4)
        nl = "\n"
        none = "nil"
        s = ((indent * level) + str(self.getKey()) + ":" + nl)
        if self.hasLeft():
            s = s + self.getLeft().display(level + 1)
        else:
            s = s + indent  * (level + 1) + none + nl
        if self.hasRight():
            s = s + self.getRight().display(level + 1)
        else:
            s = s + indent  * (level + 1) + none + nl
        return s

# b = BinaryTree(5)
# b.insertLeft(BinaryTree(4))
# b.setRight(BinaryTree(7))
# b.getRight().setRight(BinaryTree(45))
# print b.__dict__
# print b
def main():
    tree = BinaryTree(50,
            BinaryTree(30,
                BinaryTree(1),
                BinaryTree(2,
                    None,
                    BinaryTree(3)
                )
            ),
            BinaryTree(70)
        )
    user_input = "pass"
    while True:
        print tree.display()
        user_input = raw_input()
        if user_input == "q":
            break
        else:
            eval(user_input)

if __name__ == "__main__":
    main()



# def main():
#     i = ""
#     print "hello"
#     while True:
#         i = raw_input()
#         if i != "q":
#             eval(i)
#
# if __name__ == "__main__":
#     main()
