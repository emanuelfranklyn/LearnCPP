#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ArrayItem {
  public:
    T value;
    ArrayItem<T>* next = nullptr;

    ArrayItem(T value) {
      this->value = value;
      this->next = nullptr;
    }
};

template <typename T> 
class Array {
  private:
    ArrayItem<T>* head = nullptr;
    ArrayItem<T>* tail = nullptr;
    int length = 0;
  
  public:
    void push(T value) {
      ArrayItem<T>* item = new ArrayItem<T>(value);
      if (this->head == nullptr) {
        this->head = item;
        this->tail = item;
      } else {
        this->tail->next = item;
        this->tail = item;
      }
      this->length++;
    }

    void pop() {
      if (this->length == 1) {
        this->tail = nullptr;
        this->head = nullptr;
      } else {
        ArrayItem<T>* searchItem = this->head;
        for (int i = 0; i < (this->length - 2); i++) {
          if (searchItem->next != nullptr) {
            searchItem = searchItem->next;
          } else {
            break;
          }
        }
        free(searchItem->next);
        searchItem->next = nullptr;
        this->tail = searchItem;
        this->length--;
      }
    }

    void printLast() {
      if (this->tail != nullptr) {
        cout << this->tail->value << endl;
      } else {
        cout << "The array is empty" << endl;
      }
    }

    T get(int index) {
      ArrayItem<T>* searchItem = this->head;
      for (int i = 0; i < index; i++) {
        if (searchItem->next != nullptr) {
          searchItem = searchItem->next;
        } else {
          return 0;
        }
      }
      return searchItem->value;
    }
};

int main() {
  Array<string> fruits;
  fruits.push("Apple");
  fruits.push("Pinapple");
  fruits.push("Avocado");
  fruits.pop();
  fruits.printLast();
  cout << fruits.get(1) << endl;
  fruits.push("Grape");
  fruits.printLast();
  fruits.pop();
  fruits.pop();
  fruits.printLast();
  fruits.pop();
  fruits.printLast();
}