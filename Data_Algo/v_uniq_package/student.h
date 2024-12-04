#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
#include <set>
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  // std::cout << "start--------" << '\n';

  std::set<T> s;
  T* newData = new T[mSize]();
  size_t idx = 0;

  for (int i = 0;i < mSize;i++) {
    if(s.find(mData[i]) != s.end()) continue;
    newData[idx++] = mData[i];
    s.insert(mData[i]);
    // std::cout << "newData : " << newData[idx - 1] << '\n';
  }

  mSize = s.size();
  delete[] mData;
  mData = newData; 
  // std::cout << "mSize : " << mSize << ", s.size() : " << s.size() << '\n'; 
  // std::cout << "end--------" << '\n';
}

#endif
