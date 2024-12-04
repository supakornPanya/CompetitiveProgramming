#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos) {
  sort(pos.begin(), pos.end());
  int idx1 = 0, idx2 = 0;
  for(int i = 0;i < mSize;i++) {
    if(i == pos[idx2]) {
      idx2++;
      continue;
    }
    mData[(mFront + idx1) % mCap] = mData[(mFront + i) % mCap];
    idx1++;
  }
  mSize -= pos.size();
  return;
}

#endif
