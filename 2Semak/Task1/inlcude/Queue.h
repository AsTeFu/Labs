//
// Created by astefu on 9/6/19.
//

#ifndef LABA1_QUEUE_H
#define LABA1_QUEUE_H

#include <iterator>
#include <map>
#include <string>
#include <vector>

template<typename Type>
class Queue {
 private:
  const size_t capacity;
  Type* queue;
  size_t last{0};

 public:
  Queue(int capacity) : capacity(capacity) {
    queue = new Type[capacity];
  }
  ~Queue() {
    delete[](queue);
  }
  bool push_back(Type value) {
    if (last == capacity) return false;

    for (size_t i = last; i > 0; --i) queue[i] = std::move(queue[i - 1]);
    ++last;
    queue[0] = std::move(value);
    return true;
  }
  bool push(Type value) {
    if (last == capacity) return false;

    queue[last++] = std::move(value);
    return true;
  }
  Type pop() {
    return std::move(queue[--last]);
  }
  Type pop_back() {
    Type value = std::move(queue[0]);
    for (size_t i = 0; i < last - 1; ++i) queue[i] = std::move(queue[i + 1]);
    --last;
    return value;
  }
  bool isEmpty() const {
    return last == 0;
  }
  size_t size() {
    return last;
  }
  const Type* at(size_t i) const {
    return &queue[i];
  }
};

#endif  // LABA1_QUEUE_H
