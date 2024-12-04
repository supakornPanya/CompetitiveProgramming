#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(a - begin() > b - begin()) {
    T* temp = a; a = b; b = temp;
  }
  // std::cout << !(a + m - 1 < b) << " " << (m <= 0) << " " << ((b - begin()) + m > mSize) << '\n';
  if(!(a + m - 1 < b) || m <= 0 || (b - begin()) + m > mSize || a - begin() < 0) return false;
  // std::cout << "size " << b-begin() << ", mSize : " << mSize << '\n';

  for(int i = 0;i < m;i++) {
    // std::cout << "a : " << *a << ", b : " << *b << '\n';
    std::swap(*a, *b);
    a++; b++;
  }

  return true;
}

#endif
