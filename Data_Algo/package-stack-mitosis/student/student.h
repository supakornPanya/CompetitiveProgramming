


//copy 1 round----------------------------------------------------------
// #ifndef __STACK_STUDENT_H__
// #define __STACK_STUDENT_H__
// #include "stack.h"

// template <typename T>
// void CP::stack<T>::mitosis(int a, int b) {
//     expand(mSize + (b - a + 1));
//     T* arr1 = new T[b - a + 1]();
//     //after mitosis
//     for (size_t i = 0;i < a;i++) {
//         mData[mSize + b - a - i] = mData[(mSize - 1) - i];
//     } //mData[mSize + (expand) - i] = mData[Size - i]

//     //mitosis
//     for (size_t i = 0;i < b - a + 1;i++) {
//         arr1[i] = mData[(mSize - b - 1) + i];
//     }
//     for (size_t i = 0;i < (b - a + 1);i++) {
//         mData[(mSize - b - 1) + i * 2] = arr1[i];
//         mData[(mSize - b - 1) + (i * 2 + 1)] = arr1[i];
//     }

//     mSize = mSize + (b - a + 1);
//     delete[] arr1;
// }

// #endif


//copy 2 round----------------------------------------------------------
// #ifndef __STACK_STUDENT_H__
// #define __STACK_STUDENT_H__
// #include "stack.h"

// template <typename T>
// void CP::stack<T>::mitosis(int a, int b) {
//     expand(mSize + (b - a + 1));
//     T* arr1 = new T[b - a + 1]();
//     T* arr2 = new T[b];
//     //copy value
//     for (size_t i = 0;i < b - a + 1;i++) {
//         arr1[i] = mData[(mSize - b - 1) + i];
//     } 
//     for (size_t i = 0;i < a;i++) {
//         arr2[i] = mData[(mSize - a) + i];
//     }

//     //assign value
//     for (size_t i = 0;i < (b - a + 1);i++) {
//         mData[(mSize - b - 1) + i * 2] = arr1[i];
//         mData[(mSize - b - 1) + (i * 2 + 1)] = arr1[i];
//     }
//     for (size_t i = 0;i < a;i++) {
//         // std::cout << ((mSize + b - a - a + 1) + i) << " ";
//         mData[(mSize + b - a - a  + 1) + i] = arr2[i];
//     } 
//     // std::cout << '\n';

//     mSize = mSize + (b - a + 1);
//     delete[] arr1;
//     delete[] arr2;
// }

// #endif
