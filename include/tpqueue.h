// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
     T arr[100];
     int begin = 0, end = 0;

 public:
     void push(T item) {
         int i = end;
         while (item.prior > arr[i % size].prior && --i >= begin) {
             arr[(i + 1) % size] = arr[i % size];
         }
         end++;
         arr[(i + 1) % size] = item;
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
