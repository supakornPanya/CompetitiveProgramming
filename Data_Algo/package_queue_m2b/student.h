#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  T temp = mData[(mFront + pos) % mCap];

  // for(int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';

  int i = 0;
  while(i + pos < mSize) {
    // std::cout << i << " : " << mData[(pos + i) % mCap] << " " << mData[(pos + i - 1) % mCap] << '\n';
    mData[(mFront + pos + i) % mCap] = mData[(mFront + pos + i + 1) % mCap];
    i++;
  }

  mData[(mFront + mSize - 1) % mCap] = temp;

  // for (int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';
}

#endif
