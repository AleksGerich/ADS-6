// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
     T arr[100];
     int begin = 0, end = 0;

 public:
     void push(const T item) {
         for (int i = end; i >= begin; i--) {
             if (item.prior > arr[(i - 1) % size].prior && i > begin) {
                 arr[i % size] = arr[(i - 1) % size];
             } else {
                 arr[i % size] = item;
                 break;
             }
         }
         end++;
     }
     T pop() {
         return arr[(begin++) % size];
     }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
