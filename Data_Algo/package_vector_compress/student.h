#ifndef __STUDENT_H_
#define __STUDENT_H_

//comment this when pass in grader
#include "vector.h"

template <typename T>
void CP::vector<T>::compress() {
    T *arr = new T[mCap]();
    if(mCap == mSize) return;
    for(size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
    }
    delete [] mData;
    mData = arr;
    mCap = mSize;
}

#endif
