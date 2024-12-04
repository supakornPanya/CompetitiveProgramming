#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include <bits/stdc++.h>

int ans;
template <typename KeyT,
    typename MappedT,
    typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int& aux) {
    if (n == NULL) return 0;
    int l = my_recur(n->left, aux);
    int r = my_recur(n->right, aux);
    ans = std::max(ans, l + r);
    return 1 + std::max(l, r);
}

template <typename KeyT,
    typename MappedT,
    typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    ans = -1;
    if (mRoot == NULL) return -1;
    if (mRoot->left == NULL && mRoot->right == NULL) return 0;
    int fuxk;
    my_recur(mRoot, fuxk);
    return ans;
}

#endif
