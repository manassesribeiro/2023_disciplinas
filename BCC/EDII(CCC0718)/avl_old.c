// AVL Tree
// ------------------------------------------------------------
// Programmer: Dr. Mohamed Aboutabl
// Date: 03/21/2017
// Class: CSCI 223 F | TR 4:30PM
// ------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "avl.h"

typedef struct {
    char *key;
} KeyType;

typedef struct {
    char *value;
}  ValueType;

typedef struct sAVLTree {
    KeyType key;
    ValueType value;
    struct sAVLTree *left;
    struct sAVLTree *right;
    int height;
} AVLTree;



// ------------------------------------------------------------
// AVL Tree Functions
// ------------------------------------------------------------
// ------------------------------------------------------------
// Function: avlCreate
// Pre: none
// Post: returns a pointer to an empty AVL tree
// ------------------------------------------------------------
AVLTree avlCreate()
{
    return NULL;
}

// ------------------------------------------------------------
// Function: avlDestroy
// Pre: tree is a pointer to a valid AVL tree
// Post: frees all memory allocated to the tree
// ------------------------------------------------------------
void avlDestroy(AVLTree tree)
{
    if (tree == NULL)
        return;
    avlDestroy(tree->left);
    avlDestroy(tree->right);
    free(tree);
}

// ------------------------------------------------------------
// Function: avlInsert
// Pre: tree is a pointer to a valid AVL tree
//      key is a pointer to a valid key
//      value is a pointer to a valid value
// Post: inserts the key/value pair into the tree
//       if the key already exists, the value is updated
// ------------------------------------------------------------

AVLTree avlInsert(AVLTree tree, KeyType key, ValueType value)
{
    if (tree == NULL)
    {
        tree = (AVLTree) malloc(sizeof(struct AVLNode));
        assert(tree != NULL);
        tree->key = key;
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
        tree->height = 0;
        return tree;
    }
    if (strcmp(key, tree->key) < 0)
        tree->left = avlInsert(tree->left, key, value);
    else if (strcmp(key, tree->key) > 0)
        tree->right = avlInsert(tree->right, key, value);
    else
        tree->value = value;
    tree = avlBalance(tree);
    return tree;
}

// ------------------------------------------------------------
// Function: avlFind
// Pre: tree is a pointer to a valid AVL tree
//      key is a pointer to a valid key
// Post: returns a pointer to the value associated with the key
//       or NULL if the key is not found
// ------------------------------------------------------------

ValueType avlFind(AVLTree tree, KeyType key)
{
    if (tree == NULL)
        return NULL;
    if (strcmp(key, tree->key) < 0)
        return avlFind(tree->left, key);
    else if (strcmp(key, tree->key) > 0)
        return avlFind(tree->right, key);
    else
        return tree->value;
}

// ------------------------------------------------------------
// Function: avlPrint
// Pre: tree is a pointer to a valid AVL tree
// Post: prints the tree in order
// ------------------------------------------------------------
void avlPrint(AVLTree tree)
{
    if (tree == NULL)
        return;
    avlPrint(tree->left);
    printf("%s\n", tree->key);
    avlPrint(tree->right);
}

// ------------------------------------------------------------
// Function: avlBalance
// Pre: tree is a pointer to a valid AVL tree
// Post: balances the tree and returns a pointer to the root
// ------------------------------------------------------------
AVLTree avlBalance(AVLTree tree)
{
    int balance;
    if (tree == NULL)
        return NULL;
    tree->left = avlBalance(tree->left);
    tree->right = avlBalance(tree->right);
    balance = avlHeight(tree->left) - avlHeight(tree->right);
    if (balance > 1)
    {
        if (avlHeight(tree->left->left) >= avlHeight(tree->left->right))
            tree = avlRotateRight(tree);
        else
            tree = avlRotateLeftRight(tree);
    }
    else if (balance < -1)
    {
        if (avlHeight(tree->right->right) >= avlHeight(tree->right->left))
            tree = avlRotateLeft(tree);
        else
            tree = avlRotateRightLeft(tree);
    }
    tree->height = avlHeight(tree);
    return tree;
}

// ------------------------------------------------------------
// Function: avlHeight
// Pre: tree is a pointer to a valid AVL tree
// Post: returns the height of the tree
// ------------------------------------------------------------
int avlHeight(AVLTree tree)
{
    int leftHeight, rightHeight;
    if (tree == NULL)
        return -1;
    leftHeight = avlHeight(tree->left);
    rightHeight = avlHeight(tree->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// ------------------------------------------------------------
// Function: avlRotateRight
// Pre: tree is a pointer to a valid AVL tree
// Post: performs a right rotation and returns a pointer to the
//       root of the new tree
// ------------------------------------------------------------
AVLTree avlRotateRight(AVLTree tree)
{
    AVLTree temp;
    temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    tree->height = avlHeight(tree);
    temp->height = avlHeight(temp);
    return temp;
}

// ------------------------------------------------------------
// Function: avlRotateLeft
// Pre: tree is a pointer to a valid AVL tree
// Post: performs a left rotation and returns a pointer to the
//       root of the new tree
// ------------------------------------------------------------
AVLTree avlRotateLeft(AVLTree tree)
{
    AVLTree temp;
    temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    tree->height = avlHeight(tree);
    temp->height = avlHeight(temp);
    return temp;
}

// ------------------------------------------------------------
// Function: avlRotateLeftRight
// Pre: tree is a pointer to a valid AVL tree
// Post: performs a left/right rotation and returns a pointer to
//       the root of the new tree
// ------------------------------------------------------------
AVLTree avlRotateLeftRight(AVLTree tree)
{
    tree->left = avlRotateLeft(tree->left);
    return avlRotateRight(tree);
}

// ------------------------------------------------------------
// Function: avlRotateRightLeft
// Pre: tree is a pointer to a valid AVL tree
// Post: performs a right/left rotation and returns a pointer to
//       the root of the new tree
// ------------------------------------------------------------
AVLTree avlRotateRightLeft(AVLTree tree)
{
    tree->right = avlRotateRight(tree->right);
    return avlRotateLeft(tree);
}

// ------------------------------------------------------------
// Function: avlRemove
// Pre: tree is a pointer to a valid AVL tree
//      key is a pointer to a valid key
// Post: removes the key/value pair from the tree
//       if the key is not found, the tree is unchanged
// ------------------------------------------------------------
AVLTree avlRemove(AVLTree tree, KeyType key)
{
    if (tree == NULL)
        return NULL;
    if (strcmp(key, tree->key) < 0)
        tree->left = avlRemove(tree->left, key);
    else if (strcmp(key, tree->key) > 0)
        tree->right = avlRemove(tree->right, key);
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }
        else if (tree->left == NULL)
        {
            AVLTree temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            AVLTree temp = tree->left;
            free(tree);
            return temp;
        }
        else
        {
            AVLTree temp = tree->right;
            while (temp->left != NULL)
                temp = temp->left;
            strcpy(tree->key, temp->key);
            tree->value = temp->value;
            tree->right = avlRemove(tree->right, temp->key);
        }
    }
    tree = avlBalance(tree);
    return tree;
}

// ------------------------------------------------------------
// Function: avlCount
// Pre: tree is a pointer to a valid AVL tree
// Post: returns the number of nodes in the tree
// ------------------------------------------------------------
int avlCount(AVLTree tree)
{
    if (tree == NULL)
        return 0;
    return 1 + avlCount(tree->left) + avlCount(tree->right);
}

// ------------------------------------------------------------
// Function: avlMin
// Pre: tree is a pointer to a valid AVL tree
// Post: returns a pointer to the node with the smallest key
//       or NULL if the tree is empty
// ------------------------------------------------------------
AVLTree avlMin(AVLTree tree)
{
    if (tree == NULL)
        return NULL;
    if (tree->left == NULL)
        return tree;
    return avlMin(tree->left);
}

// ------------------------------------------------------------
// Function: avlMax
// Pre: tree is a pointer to a valid AVL tree
// Post: returns a pointer to the node with the largest key
//       or NULL if the tree is empty
// ------------------------------------------------------------
AVLTree avlMax(AVLTree tree)
{
    if (tree == NULL)
        return NULL;
    if (tree->right == NULL)
        return tree;
    return avlMax(tree->right);
}

// ------------------------------------------------------------
// Function: avlPredecessor
// Pre: tree is a pointer to a valid AVL tree
//      key is a pointer to a valid key
// Post: returns a pointer to the node with the largest key
//       that is smaller than the given key
//       or NULL if the key is not found
// ------------------------------------------------------------
AVLTree avlPredecessor(AVLTree tree, KeyType key)
{
    if (tree == NULL)
        return NULL;
    if (strcmp(key, tree->key) < 0)
        return avlPredecessor(tree->left, key);
    else if (strcmp(key, tree->key) > 0)
    {
        AVLTree temp = avlPredecessor(tree->right, key);
        if (temp == NULL)
            return tree;
        else
            return temp;
    }
    else
        return avlMax(tree->left);
}

// ------------------------------------------------------------
// Function: avlSuccessor
// Pre: tree is a pointer to a valid AVL tree
//      key is a pointer to a valid key
// Post: returns a pointer to the node with the smallest key
//       that is larger than the given key
//       or NULL if the key is not found
// ------------------------------------------------------------
AVLTree avlSuccessor(AVLTree tree, KeyType key)
{
    if (tree == NULL)
        return NULL;
    if (strcmp(key, tree->key) < 0)
    {
        AVLTree temp = avlSuccessor(tree->left, key);
        if (temp == NULL)
            return tree;
        else
            return temp;
    }
    else if (strcmp(key, tree->key) > 0)
        return avlSuccessor(tree->right, key);
    else
        return avlMin(tree->right);
}

// ------------------------------------------------------------
// Function: avlRank
// Pre: tree is a pointer to a valid AVL tree
//      key is a pointer to a valid key
// Post: returns the number of keys that are smaller than the
//       given key
// ------------------------------------------------------------
int avlRank(AVLTree tree, KeyType key)
{
    if (tree == NULL)
        return 0;
    if (strcmp(key, tree->key) < 0)
        return avlRank(tree->left, key);
    else if (strcmp(key, tree->key) > 0)
        return 1 + avlCount(tree->left) + avlRank(tree->right, key);
    else
        return avlCount(tree->left);
}

// ------------------------------------------------------------
// Function: avlSelect
// Pre: tree is a pointer to a valid AVL tree
//      rank is a valid rank
// Post: returns a pointer to the node with the given rank
//       or NULL if the rank is invalid
// ------------------------------------------------------------
AVLTree avlSelect(AVLTree tree, int rank)
{
    int leftCount;
    if (tree == NULL)
        return NULL;
    leftCount = avlCount(tree->left);
    if (rank < leftCount)
        return avlSelect(tree->left, rank);
    else if (rank > leftCount)
        return avlSelect(tree->right, rank - leftCount - 1);
    else
        return tree;
}

// ------------------------------------------------------------
// Function: avlRange
// Pre: tree is a pointer to a valid AVL tree
//      key1 is a pointer to a valid key
//      key2 is a pointer to a valid key
// Post: returns the number of keys that are between key1 and
//       key2 (inclusive)
// ------------------------------------------------------------
int avlRange(AVLTree tree, KeyType key1, KeyType key2)
{
    if (tree == NULL)
        return 0;
    if (strcmp(key1, tree->key) <= 0 && strcmp(key2, tree->key) >= 0)
        return 1 + avlRange(tree->left, key1, key2) + avlRange(tree->right, key1, key2);
    else if (strcmp(key1, tree->key) > 0)
        return avlRange(tree->right, key1, key2);
    else
        return avlRange(tree->left, key1, key2);
}

// ------------------------------------------------------------
// Function: avlRangePrint
// Pre: tree is a pointer to a valid AVL tree
//      key1 is a pointer to a valid key
//      key2 is a pointer to a valid key
// Post: prints all keys that are between key1 and key2
//       (inclusive) in order
// ------------------------------------------------------------
void avlRangePrint(AVLTree tree, KeyType key1, KeyType key2)
{
    if (tree == NULL)
        return;
    if (strcmp(key1, tree->key) < 0)
        avlRangePrint(tree->left, key1, key2);
    if (strcmp(key1, tree->key) <= 0 && strcmp(key2, tree->key) >= 0)
        printf("%s\n", tree->key);
    if (strcmp(key2, tree->key) > 0)
        avlRangePrint(tree->right, key1, key2);
}

// ------------------------------------------------------------
// Function: avlRangeSearch
// Pre: tree is a pointer to a valid AVL tree
//      key1 is a pointer to a valid key
//      key2 is a pointer to a valid key
// Post: returns a pointer to a new AVL tree that contains all
//       keys that are between key1 and key2 (inclusive)
// ------------------------------------------------------------
AVLTree avlRangeSearch(AVLTree tree, KeyType key1, KeyType key2)
{
    AVLTree temp = NULL;
    if (tree == NULL)
        return NULL;
    if (strcmp(key1, tree->key) < 0)
        temp = avlRangeSearch(tree->left, key1, key2);
    if (strcmp(key1, tree->key) <= 0 && strcmp(key2, tree->key) >= 0)
        temp = avlInsert(temp, tree->key, tree->value);
    if (strcmp(key2, tree->key) > 0)
        temp = avlRangeSearch(tree->right, key1, key2);
    return temp;
}

