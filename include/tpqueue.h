// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
     T arr[size] = {0};
     int begin, end, count;

 public:
     TPQueue() : begin(0), end(0), count(0) { }
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
         count += 1;
     }
     int checkSize() {
         return size;
     }
     T pop() {
         return arr[(begin++) % size];
     }
     T gey() const {
         return arr[begin];
     }
     bool isEmpty() const {
         return count == 0;
     }
     bool isFull() const {
         return count == size;
     }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
