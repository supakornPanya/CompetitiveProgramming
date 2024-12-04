#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
  size_t pos = position - begin();
  size_t idx1 = 0, idx2 = 0;
  mSize = mSize + (last - first);
  T* newData = new T[mSize]();
  // std::cout << "size : " << mSize + (last - first) << ", pos :  " << pos << ", idx : " << idx << '\n';

  //before 
  for(size_t i = 0;i < pos;i++) {
    newData[idx1++] = mData[idx2++];
  }

  //mid -> new value
  while (first != last) {
    newData[idx1++] = *first;
    first++;
  }

  //after
  while(idx1 < mSize) {
    newData[idx1++] = mData[idx2++];
  }

  delete[] mData;
  mData = newData;
  mCap = mSize;

  // std::cout << "mSize : " << mSize << '\n';
}

#endif
