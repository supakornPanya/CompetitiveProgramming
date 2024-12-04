#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  aux = (aux)? 0 : 1; 
}

template <typename T>
const T& CP::queue<T>::front() const {
  if (aux == 1) {return mData[(mFront + mSize - 1) % mCap];}
  else {return mData[mFront];}  
}

template <typename T>
const T& CP::queue<T>::back() const {
  if(aux == 1) { return mData[mFront];}
  else { return mData[(mFront + mSize - 1) % mCap]; }
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize + 1);
  if (aux == 1){
    mData[(mFront - 1 + mCap) % mCap] = element;
    mFront = (mFront + mCap - 1) % mCap;
    // mData[mFront] = element;
  } else {
    mData[(mFront + mSize) % mCap] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  if (aux == 0) {
    mFront = (mFront + 1) % mCap;
  }
  mSize--;
}

#endif