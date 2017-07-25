# Eliel
# Lecture 5 of 6.006
# Binary Trees

import random

class bintree(object):
    def __init__(self, key = None, parent = None, \
        left = None, right = None):
        self.key = key
        self.parent = parent
        self.left = left
        self.right = right
    def __str__(self):
        return str(self.key)
    def __int__(self):
        return int(self.key)
    def getKey(self):
        return self.getKey
    def getLeft(self):
        return self.left
    def getRight(self):
        return self.right
    def getParent(self):
        return self.parent
    def setParent(self, tree):
        self.parent = tree
        return self
    def find(self, key):
        if (self.key == key):
            return self
        elif self.left != None and key < self.key:
            return self.left.find(key)
        elif self.right != None and self.key <= key:
            return self.right.find(key)
        else:
            return None
    def root(self):
        root = self
        while root.parent != None:
            root = root.parent
        return root
    def rotateLeft(self):
        #root = self
        #pivot = self.right
        r = self
        p = self.right
        t = self.parent
        a = r.left
        b = p.left
        c = p.right
        p.parent = t
        r.parent = p
        r.right = b
        p.left = r
    def rotateRight(self):
        #root = self
        #pivot = self.left
        r = self
        p = self.left
        t = self.parent
        a = r.right
        b = p.right
        c = p.left
        p.parent = t
        r.left = b
        r.left = b
        p.right = r
    def delete(self):
        if (node.left == None and node.right == None):
            del node # delete leaf
        elif(node.left != None and node.right == None):
            node.rotateLeft()
            node.delete()
        elif(node.left == None and node.right != None):
            node.rotateRight()
            node.delete()
        else:
            # can randomize or use adv. technique (e.g. avl, rb tree)
            node.rotateLeft() # prone to left biased trees
            node.delete()

    def display(self, level = 0):
        print (("        " * level) + str(self.key) + ":")
        if self.left != None:
            self.left.display(level + 1)
        if self.right != None:
            self.right.display(level + 1)
    def insertTree(self, tree):
        if tree.key < self.key:
            if self.left == None: #left
                self.left = tree.setParent(self.left)
                # can do avl balancing if need be
            else:
                # recurively insert into the left sub tree
                self.left.insert(tree)
        if self.key <= tree.key: #right
            if self.right == None:
                self.right = tree.setParent(self.right)
            else:
                self.right.insert(tree)
    def insert(self, key):
        if key < self.key:
            if self.left == None:
                self.left = bintree(key, self)
                # can do avl balancing if need be
            else:
                # recurively insert into the left sub tree
                self.left.insert(key)
        if self.key <= key:
            if self.right == None:
                self.right = bintree(key, self)
            else:
                self.right.insert(key)


# tree = bintree(int(random.random() * 100))
# for x in range(0, 20):
#     tree.insert(int(random.random() * 100))
# tree.display()

# a = tree.find(32)
# if a != None:
#     print "found 32"
#     a.display()
# a = tree.find(3)
# if a != None:
#     print "found 3"
#     a.display()
# a = tree.find(42)
# if a != None:
#     print "found 42"
#     a.display()

# create tree interpreter
tree = bintree(50)
user_input = ""
while user_input != "q":
    user_input = raw_input()
    tree.display()
    input()
