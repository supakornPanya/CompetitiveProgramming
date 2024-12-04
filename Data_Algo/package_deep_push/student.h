#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  // for(int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';

  ensureCapacity(mSize + 1);
  for(size_t i = 0;i < pos;i++) {
    // std::cout << i << " : " << mData[(mSize) - i] << " " << mData[(mSize) - i - 1] << '\n';
    mData[mSize - i] = mData[mSize - i - 1];
  }

  // for (int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';

  mData[mSize - pos] = value;
  mSize++;

  // for (int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';
}
#endif
