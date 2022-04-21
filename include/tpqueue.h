// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
     T arr[size] = {0};
     int begin, end;

 public:
     void push(const T item) {
         for (int i = end; i >= begin; i--) {
             if (i > begin && item.prior > arr[(i - 1) % size].prior) {
                 arr[i % size] = arr[(i - 1) % size];
             } else {
                 arr[i % size] = item;
                 break;
             }
         }
         end++;
     }
     T pop() {
        return arr[begin++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
