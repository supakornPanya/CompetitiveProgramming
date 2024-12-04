#ifndef _CP_LIST_INCLUDED_
#define _CP_LIST_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP {

  template <typename T>
  class list
  {
  protected:
    class node {
      friend class list;
    public:
      T data;
      node* prev;
      node* next;

      node() :
        data(T()), prev(this), next(this) {
      }

      node(const T& data, node* prev, node* next) :
        data(T(data)), prev(prev), next(next) {
      }
    };

    class list_iterator {
      friend class list;
    protected:
      node* ptr;
    public:

      list_iterator() : ptr(NULL) {}

      list_iterator(node* a) : ptr(a) {}

      list_iterator& operator++() {
        ptr = ptr->next;
        return (*this);
      }

      list_iterator& operator--() {
        ptr = ptr->prev;
        return (*this);
      }

      list_iterator operator++(int) {
        list_iterator tmp(*this);
        operator++();
        return tmp;

      }
      list_iterator operator--(int) {
        list_iterator tmp(*this);
        operator--();
        return tmp;
      }

      T& operator*() { return ptr->data; }
      T* operator->() { return &(ptr->data); }
      bool operator==(const list_iterator& other) { return other.ptr == ptr; }
      bool operator!=(const list_iterator& other) { return other.ptr != ptr; }
    };

  public:
    typedef list_iterator iterator;

  protected:
    node* mHeader; // pointer to a header node
    size_t mSize;


  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    list(list<T>& a) :
      mHeader(new node()), mSize(0) {
      for (iterator it = a.begin();it != a.end();it++) {
        push_back(*it);
      }
    }

    // default constructor
    list() :
      mHeader(new node()), mSize(0) {
    }

    // copy assignment operator using copy-and-swap idiom
    list<T>& operator=(list<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mHeader, other.mHeader);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~list() {
      clear();
      delete mHeader;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }


    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mHeader->next);
    }

    iterator end() {
      return iterator(mHeader);
    }
    //----------------- access -----------------
    T& front() { return mHeader->next->data; }

    T& back() { return mHeader->prev->data; }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(), element);
    }

    void push_front(const T& element) {
      insert(begin(), element);
    }

    void pop_back() {
      erase(iterator(mHeader->prev));
    }

    void pop_front() {
      erase(begin());
    }

    iterator insert(iterator it, const T& element) {
      node* n = new node(element, it.ptr->prev, it.ptr);
      it.ptr->prev->next = n;
      it.ptr->prev = n;
      mSize++;
      return iterator(n);
    }

    iterator erase(iterator it) {
      iterator tmp(it.ptr->next);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
      return tmp;
    }

    void clear() {
      while (mSize > 0) erase(begin());
    }

    void print() {
      std::cout << " Header address = " << (mHeader) << std::endl;
      int i = 0;
      iterator before;
      int ii = 0;
      for (iterator it = begin();it != end();before = it, it++, i++) {
        std::cout << "Node " << i << ": " << *it;
        std::cout << " (prev = " << it.ptr->prev << ", I'm at " << it.ptr << ", next = " << it.ptr->next << ")" << std::endl;
        ii++;
        if (ii == 20) break;
      }
    }
    // #include "student.h"
    //round 2-------------------------------------
    void splitList(list<T>& list1, list<T>& list2) {
      size_t n1 = (mSize + 1) / 2;
      size_t n2 = mSize - n1;
      node* pivot;
      node* lPivot; node* rPivot; node* start; node* last;
      // std::cout << "l : " << lPivot->data << " " << rPivot->data << '\n';

      if (n1 > 0) {
        pivot = mHeader->next;
        for (size_t i = 0;i < n1 - 1;i++) {
          pivot = pivot->next;
        }
        lPivot = pivot;
        rPivot = pivot->next;
        start = mHeader->next;
        last = mHeader->prev;
        // std::cout << "l : " << lPivot->data << " " << rPivot->data << '\n';

        node* end1 = list1.mHeader->prev;
        end1->next = start;
        start->prev = end1;
        lPivot->next = list1.mHeader;
        list1.mHeader->prev = lPivot;
      }
      if (n1 > 0 && n2 > 0) {
        node* end2 = list2.mHeader->prev;
        end2->next = rPivot;
        rPivot->prev = end2;
        last->next = list2.mHeader;
        list2.mHeader->prev = last;
      }

      mHeader->next = mHeader;
      mHeader->prev = mHeader;
      mSize = 0;
      list1.mSize += n1;
      list2.mSize += n2;
    }

    //round 1 ---------------------------------------------------------
    // void splitList(list<T>& list1, list<T>& list2) {
    //   int n1 = (mSize % 2 == 0) ? mSize / 2 : (mSize / 2) + 1;
    //   int n2 = mSize / 2;

    //   if (n1 > 0) {
    //     //find mid list this
    //     node* mThis = mHeader->next;
    //     for (int i = 0;i < n1 - 1;i++) {
    //       mThis = mThis->next;
    //     }
    //     node* mThis2 = mThis->next;

    //     (list1.mHeader->prev)->next = (mHeader->next); //last list1 <-> first this
    //     (mHeader->next)->prev = (list1.mHeader->prev); //first this <-> last list1
    //     mThis->next = list1.mHeader; //last this <-> mHeader list1
    //     list1.mHeader->prev = mThis;//mHeader list1 <-> last this

    //     if (n2 > 0) {
    //       (list2.mHeader->prev)->next = mThis2; //last list2 <-> first2 this //mThis 
    //       (mThis2)->prev = (list2.mHeader->prev); //last list2 <-> first2 this //mThis
    //       (mHeader->prev)->next = list2.mHeader; //mid this <-> mHeader list2
    //       list2.mHeader->prev = (mHeader->prev);//mid this <-> mHeader list2
    //     }
    //   }


    //   //set up *this
    //   mHeader->prev = mHeader;
    //   mHeader->next = mHeader;
    //   mSize = 0;

    //   list1.mSize += n1;
    //   list2.mSize += n2;
    // }

  };

}

#endif


