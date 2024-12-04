//round 2-----------------------------------------------------------
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <bits/stdc++.h>
using namespace std;
#include "priority_queue.h"

template <typename T, typename Comp >
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
  if (k == 1) {
    return mData[0];
  } else {
    vector<T> v;
    for (int i = 0;i < 7 && i < mSize;i++) {
      v.push_back(mData[i]);
    }
    sort(v.rbegin(), v.rend(), mLess);
    if (k == 2) return v[1];
    else return v[2];
  }
}

#endif


//round 1-----------------------------------------------------------
// #ifndef __STUDENT_H__
// #define __STUDENT_H__

// #include <algorithm>
// #include <vector>
// #include "priority_queue.h"

// template <typename T, typename Comp >
// T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
//   if (k == 1) {
//     return mData[0];
//   } else if (k == 2) {
//     if (mLess(mData[1], mData[2])) return mData[2];
//     else return mData[1];
//   } else if (k == 3) {
//     std::vector<T> v;
//     for (size_t i = 0;i < 7;i++) {
//       v.push_back(mData[i]);
//     }
//     std::sort(v.begin(), v.end(), mLess);
//     return *(v.end() - k);
//   }
// }

// #endif
