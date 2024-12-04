#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

long long ans = 0;
template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
  if(n == NULL) return 0;
  if(n->left == NULL && n->right == NULL) {
    ans += aux;
    return 0;
  }
  long long l = my_recur(n->left, aux + 1);
  long long r = my_recur(n->right, aux + 1);
  return 0;
}

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  my_recur(mRoot, 0);
  return ans;
}

#endif



//round 1--------------------------------------------------
// #ifndef __STUDENT_H_
// #define __STUDENT_H_

// #include "map_bst.h"

// template <typename KeyT, typename MappedT, typename CompareT>
// long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
//   // std::cout << "node : " << (n->data).first << ", aux : " << aux << '\n';
//   if (n->left == NULL && n->right == NULL) return aux;
//   long long l = 0, r = 0;
//   if (n->left != NULL) {
//     l = my_recur(n->left, aux + 1);
//   }
//   if (n->right != NULL) {
//     r = my_recur(n->right, aux + 1);
//   }
//   return l + r;
// }

// template <typename KeyT, typename MappedT, typename CompareT>
// long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
//   if (mRoot == NULL) return 0;
//   long long ans = my_recur(mRoot, 0);
//   return ans;
// }

// #endif
