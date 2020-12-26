/*
Learning classes OOP and Inheritance with function and Operator overloading.
*/

#include <iostream>
#include "book.h"
#include "calc.h"
#include "queue.h"

void testSelector();
void testBook();
void testCalc();
void testQueue();

int main() {
  system("clear");
  testSelector();
  return 0;
}

void testSelector(){
  int option = -1;
  std::cout << "\nSelect Test Case:\n" << "1: Book Class\n" << "2: Calc Class\n" << "3: Queue Class \n" << std::endl;
  std::cin >> option;
  switch(option){
    case 1:{
      //Test Book
      system("clear");
      testBook();
      break;
    }
    case 2:{
      //test calc
      system("clear");
      testCalc();
      break;
    }
    case 3:{
      //test Queue
      system("clear");
      testQueue();
      break;
    }
    /*
    case 3:{}
      break;
    }
    case 4:{
      break;
    }
    */
    default:{
      system("clear");
      std::cout << "Invalid Input" << std::endl;
      testSelector();
    }
  }
}

void testBook(){
  std::cout << "TEST BOOK CLASS" << std::endl;

  Book book1 = Book("test1", "test2", "test3");
  std::cout << book1.to_string() << std::endl;
  //destructor
  book1.~Book(); //destructor

  std::cout << "End Book" << std::endl;
  testSelector();

}

void testCalc(){
  std::cout << "\nTEST CALC CLASS" << std::endl;
  calc val1 = calc(6);

  //functions
  std::cout << "\nTest Functions" << std::endl;
  val1.powOf(2);//expected 36
  std::cout << "6 ^ 2 = " << val1.getValue() << std::endl;
  val1.mul(2);//expected 72
  std::cout << "36 * 2 = " << val1.getValue() << std::endl;

  //chained functions
  std::cout << "\nTest Chained Functions" << std::endl;
  val1.setValue(0);
  val1.add(2).mul(10).div(1).pow2(); // expected 400
  std::cout << "(((0+2)*10)/1)^2 = " << val1.getValue() << std::endl;

  //2 calc Operators with Operators overloading
  //return type calc
  std::cout << "\nTest Operators : return type calc" << std::endl;
  val1.setValue(20);
  calc val2 = calc(2);

  std::cout << "val1 = " << val1.getValue() << "\t" << "val2 = " << val2.getValue() << std::endl;
  std::cout << "val1 + val2 = " << (val1 + val2).getValue()  << std::endl;
  std::cout << "val1 - val2 = " << (val1 - val2).getValue() << std::endl;
  std::cout << "val1 * val2 = " << (val1 * val2).getValue() << std::endl;
  std::cout << "val1 / val2 = " << (val1 / val2).getValue() << std::endl;

  // return type bool
  std::cout << "val1 = " << val1.getValue() << "\t" << "val2 = " << val2.getValue() << std::endl;
  std::cout << "\nTest Operators : return type bool" << std::endl;
  std::cout << "val1 > val2 = " << (val1 > val2) << std::endl;
  std::cout << "val1 < val2 = " << (val1 < val2) << std::endl;
  std::cout << "val1 >= val2 = " << (val1 >= val2) << std::endl;
  std::cout << "val1 <= val2 = " << (val1 <= val2) << std::endl;
  std::cout << "val1 == val2 = " << (val1 == val2) << std::endl;
  
  //set val1 == val2
  val2.setValue(20);

  std::cout << "\nval1 = " << val1.getValue() << "\t" << "val2 = " << val2.getValue() << std::endl;
  std::cout << "val1 > val2 = " << (val1 > val2) << std::endl;
  std::cout << "val1 < val2 = " << (val1 < val2) << std::endl;
  std::cout << "val1 >= val2 = " << (val1 >= val2) << std::endl;
  std::cout << "val1 <= val2 = " << (val1 <= val2) << std::endl;
  std::cout << "val1 == val2 = " << (val1 == val2) << std::endl;
  
  //destructors
  val1.~calc();
  val2.~calc();
  std::cout << "End Calc" << std::endl;
  testSelector();
}

void testQueue(){
  std::cout << "\nTEST Queue Class" << std::endl;
  
  std::cout << "\nCase 1: With integers" << std::endl;
  SimpleQueue<int, 5> intQueue;

  std::cout << "\nintQueue with size 5 -> Enqueue 10 -> Enqueue 20 -> print Peek ->  Dequeue -> Enqueue 30, 40, 50 - > Dequeue -> Print" << std::endl;
  
  intQueue.Enqueue(10);
  intQueue.Enqueue(20);
  
  std::cout << "Peek: " << intQueue.Peek() << std::endl;
  std::cout << "Dequeue: " << intQueue.Dequeue() << std::endl;

  std::cout << "Display Queue: ";
  intQueue.Print();
  intQueue.Enqueue(30);
  intQueue.Enqueue(40);
  intQueue.Enqueue(50);
  
  std::cout << "Display Queue: ";
  intQueue.Print();

  std::cout << "Dequeue: " << intQueue.Dequeue() << std::endl;

  std::cout << "Display Queue: ";
  intQueue.Print();

  intQueue.~SimpleQueue();
  std::cout << "\nCase 1 End." << std::endl;

  std::cout << "\nCase 2: With Custom Class Book using a loop" << std::endl;
  SimpleQueue<Book, 10> bookQueue;

  std::cout << "\nInit with size 10 -> queue 10 Books [0,9] -> Display -> Dequeue * 5 -> Enqueue * 2 -> Display" << std::endl;
  for(int i = 0; i < bookQueue.length(); i++){
      bookQueue.Enqueue(Book(
        "Title_" + std::to_string(i+1), 
        "Author_" + std::to_string(i+1), 
        "ISBN_" + std::to_string(i+1)));
    }
  
  std::cout << "Queue Display: ";
  for(int i = 0; i < bookQueue.NumItems(); i++){
    std::cout<< bookQueue.getIndexValue(i).to_string() << "\t";
  }
  std::cout << std::endl;

  std::cout << "\nDequeue 5 Books: " << std::endl;
  for(int i = 0; i < 5; i++){
    std::cout << "Dequeue " << i+1 << ": " << bookQueue.Dequeue().to_string() << std::endl;
  }

  std::cout << "\nEnqueue 2 Books. " << std::endl;
  for(int i = 0; i < 2 ; i++){
    bookQueue.Enqueue(Book(
      "NewTitle_ " + std::to_string(i+1),
      "New_Author_ " + std::to_string(i+1),
      "New_ISBN_ " + std::to_string(i+1)));
  }

  std::cout << "Queue Display: ";
  for(int i = 0; i < bookQueue.NumItems(); i++){
    std::cout<< bookQueue.getIndexValue(i).to_string() << "\t";
  }
  std::cout << std::endl;
  
  bookQueue.~SimpleQueue();
  std::cout << "\nCase 2 End." << std::endl;

  std::cout << "\nCase 3: With Custom Class Calc using a loop" << std::endl;
  SimpleQueue<calc, 10> calcQueue;

  std::cout << "\nInit with size 10 -> queue 10 calcs [0,9] -> Display -> Dequeue * 3 -> Enqueue *2 -> Dequeue * 2 -> Display" << std::endl;
  for(int i = 0; i < calcQueue.length(); i++){
    calc temp = calc(i);
    calcQueue.Enqueue(temp);
  }

  std::cout << "Queue Display: ";
  for(int i = 0; i < calcQueue.NumItems(); i++){
    std::cout<< calcQueue.getIndexValue(i).getValue()<< "\t";
  }
  std::cout << std::endl;
  std::cout << "Dequeue1: " << calcQueue.Dequeue().getValue() << std::endl;
  std::cout << "Dequeue2: " << calcQueue.Dequeue().getValue() << std::endl;
  std::cout << "Dequeue3: " << calcQueue.Dequeue().getValue() << std::endl;
  
  std::cout << "Enqueue 17" << std::endl;
  std::cout << "Enqueue 18" << std::endl;
  calcQueue.Enqueue(calc(17));
  calcQueue.Enqueue(calc(18));
  
  std::cout << "Dequeue1: " << calcQueue.Dequeue().getValue() << std::endl;
  std::cout << "Dequeue2: " << calcQueue.Dequeue().getValue() << std::endl;
  

  //calcQueue.Print();
  std::cout << "Queue Display: ";
  for(int i = 0; i < calcQueue.NumItems(); i++){
    std::cout<< calcQueue.getIndexValue(i).getValue()<< "\t";
  }
  std::cout << std::endl;
  std::cout << "Case 2 End." << std::endl;
  
  calcQueue.~SimpleQueue();
  std::cout << "\nEnd Queue" << std::endl;
  testSelector();
}