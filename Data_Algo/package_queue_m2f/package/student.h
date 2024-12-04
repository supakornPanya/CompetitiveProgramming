#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    T temp = mData[(mFront + pos) % mCap];

    // for(int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';

    int i = pos - 1;
    while (i >= 0) {
        // std::cout << i << " : " << mData[(mFront + i) % mCap] << " " << mData[(mFront + i - 1) % mCap] << '\n';
        mData[(mFront + i + 1) % mCap] = mData[(mFront + i) % mCap];
        i--;
    }

    // for (int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';

    mData[(mFront) % mCap] = temp;

    // for (int i = 0;i < this->size();i++) { std::cout << mData[i] << " "; } std::cout << '\n';
}

#endif
