#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node* n) {
  if(n == NULL) return 0;
  return 1 + process(n->left) + process(n->right);
}

template <typename KeyT, typename MappedT, typename CompareT >
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(map_bst<KeyT, MappedT, CompareT>& left, map_bst<KeyT, MappedT, CompareT>& right) {
  //called is NULL
  if (mSize == 0) return std::pair<KeyT, MappedT>();

  //left
  left.clear();
  node* lSub = mRoot->left;
  if (lSub == NULL) {
    left.mRoot = NULL;
    left.mSize = 0;
  } else {
    left.mRoot = lSub;
    left.mSize = process(lSub);
  }

  //right
  right.clear();
  node* rSub = mRoot->right;
  if (rSub == NULL) {
    right.mRoot = NULL;
    right.mSize = 0;
  } else {
    right.mRoot = rSub;
    right.mSize = process(rSub);
  }

  std::pair<KeyT, MappedT> rootData = mRoot->data;
  mRoot->left = NULL;
  mRoot->right = NULL;
  mSize = 1;

  return rootData;
}

#endif

