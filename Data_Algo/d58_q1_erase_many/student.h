#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int>& pos) {
  // std::cout << "start--------" << '\n';
  
  std::vector<int> Newpos = pos;
  std::sort(Newpos.begin(), Newpos.end());
  mSize = mSize - Newpos.size();
  size_t iOld = 0, iPos = 0;
  
  for (int i = 0;i < mSize;i++) {
    while(iOld == Newpos[iPos] && iPos < pos.size()) { 
      iPos++; iOld++;
    }
    // std::cout << i << " : " << iOld << '\n';
    mData[i] = mData[iOld++];
  }
  
  // std::cout << "end--------" << '\n';
}

#endif


//erase function build in------------------------------
// #ifndef __STUDENT_H_
// #define __STUDENT_H_

// //comment this when pass in grader
// #include "vector.h"

// template <typename T>
// void CP::vector<T>::erase_many(const std::vector<int>& pos) {
//   // std::cout << "start--------" << '\n';
//   int c = 0;
//   for (int i = 0;i < pos.size();i++) {
//     // std::cout << "pos[i] : " << pos[i] << '\n';
//     erase(this->begin() + pos[i] + c);
//     c--;
//   }
//   // std::cout << "end--------" << '\n';
// }
// //
// #endif
