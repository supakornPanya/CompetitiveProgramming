#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  size_t newSize = mSize + data.size();
  T* newData = new T[newSize]();
  std::sort(data.begin(), data.end());
  // std::cout << "size : " << mSize << '\n';

  size_t iOld = 0, iData = 0;
  for(int iNew = 0;iNew < mSize + data.size();iNew++) {
    if(iOld == data[iData].first) {
      newData[iNew] = data[iData++].second;
    } else {
      newData[iNew] = mData[iOld++];
    }
  }

  mCap = newSize;
  mSize = newSize;
  delete[] mData;
  mData = newData; 
}

#endif
