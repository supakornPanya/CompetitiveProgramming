#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  idx = (idx < 0)? mSize + idx : idx;
  // std::cout << "idx : " << idx << '\n';
  return mData[(mFront + idx) % mCap];
}

#endif
