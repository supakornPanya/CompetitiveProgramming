#ifndef __STUDENT_H_
#define __STUDENT_H_

//comment this when pass in grader
#include "pair.h"

template <typename T1,typename T2>
bool CP::pair<T1,T2>::operator>=(const pair<T1,T2>& other) const {
  if(first != other.first) return first > other.first;
  if(second != other.second) return second > other.second;
  return true;
}

#endif