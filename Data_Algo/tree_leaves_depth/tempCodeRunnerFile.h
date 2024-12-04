#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
  if(n == NULL) return 0;
  long long l = my_recur(n->left, aux + 1);
  long long r = my_recur(n->right, aux + 1);
  return aux;
}

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  long long ans = my_recur(mRoot, 0);
  return ans;
}

#endif
