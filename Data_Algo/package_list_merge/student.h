#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  node* l = mHeader->prev; 
  node* r;
  auto it = ls.begin(); //pointer list
  // auto endd = ls.end()--; //pointer list
  while(it != ls.end()) {
    CP::list<T>& now = *it; //list
    // auto& now = *it;
    r = now.mHeader->next; //new r(pointer to node)
    l->next = r; //connect list
    r->prev = l; //connect list
    l = now.mHeader->prev; //new l

    now.mHeader->next = now.mHeader;
    now.mHeader->prev = now.mHeader;
    mSize += now.mSize;
    now.mSize = 0;
    it++;
  }
  //(last end in ls) with (mHeader)
  l->next = mHeader;
  mHeader->prev = l;
} 

#endif
