#include <iostream>

template<class T, int size>
class SimpleQueue{
  private: 
   int max_size = size;
   int head = 0;
   int tail = 0;
   int numItems = 0;
   T *store = new T[max_size];
  public:
    //Construc
    SimpleQueue(){
      store = new T[max_size];
    }
    
    //getters
    int Head(){return head;}
    int Tail(){return tail;}
    int NumItems(){return numItems;}
    int length(){return max_size;}
    
    //smol func
    T Peek();
    T getIndexValue(int index);
    bool isEmpty();
    bool isFull();

    //funcs
    void Enqueue(T value);
    T Dequeue();
    void Print();
};

template<class T, int size>
T SimpleQueue<T, size>::Peek(){return store[head];}

template<class T, int size>
T SimpleQueue<T, size>::getIndexValue(int index){
  //if index > size return 0
  if(index > max_size){
      return T();
  }
  return store[(head + index) % max_size];
}

template<class T, int size>
bool SimpleQueue<T, size>::isEmpty(){return numItems == 0;}

template<class T, int size>
bool SimpleQueue<T, size>::isFull(){return numItems == max_size;}

template<class T, int size>
void SimpleQueue<T, size>::Enqueue(T value){
  numItems++;
  store[tail++] = value;
  if(tail == max_size)
    tail = 0;
}

template<class T, int size>
T SimpleQueue<T, size>::Dequeue(){
  numItems--;
  T temp = store[head++];
  if(head == max_size)
    head = 0;
  return temp;
}

template<class T, int size>
void SimpleQueue<T, size>::Print(){
  if(isEmpty()){
    std::cout << "Empty Queue" << std::endl;;
  }
  int i = head;
  do{
    std::cout << store[i++] << "\t";
    if(i == max_size){i = 0;}
  }while(i != tail);
  std::cout << std::endl;
}