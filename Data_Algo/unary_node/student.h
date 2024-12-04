#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
  typename MappedT,
  typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node* n) const {
  if (n == NULL) return 0;
  size_t l = process(n->left);
  size_t r = process(n->right);
  if (n->left == NULL && n->right != NULL) return 1 + (l + r);
  if (n->left != NULL && n->right == NULL) return 1 + (l + r);
  return l + r;
}

template <typename KeyT,
  typename MappedT,
  typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::count_unary() const {
  size_t ans = process(mRoot);
  return ans;
}

#endif


//round 1 ----------------------------------------------------
// #ifndef __STUDENT_H__
// #define __STUDENT_H__

// template <typename KeyT,
//   typename MappedT,
//   typename CompareT>
// size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node* n) const {
//   if (n == NULL) return 0;
//   bool now = ((n->left == NULL && n->right != NULL) || (n->left != NULL && n->right == NULL));
//   return now + process(n->left) + process(n->right);
// }

// template <typename KeyT,
//   typename MappedT,
//   typename CompareT>
// size_t CP::map_bst<KeyT, MappedT, CompareT>::count_unary() const {
//   size_t ans = process(mRoot);
//   return ans;
// }

// #endif
