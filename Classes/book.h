#include <string>

class Book{
  private:
    std::string b_Title = "N/A"; 
    std::string b_Author = "N/A"; 
    std::string b_ISBN = "N/A";

  public:
    //Constructor
    Book();
    Book(std::string Title, std::string Author, std::string ISBN);
    
    //setters
    void set_Book(std::string title, std::string author, std::string isbn);
    void set_Title(std::string title);
    void set_Author(std::string author);
    void set_Isbn(std::string isbn);
    
    //getters
    std::string get_Title();
    std::string get_Author();
    std::string get_Isbn();

    //functions
    std::string to_string();
};

Book::Book(){

}  
Book::Book(std::string Title, std::string Author, std::string ISBN){
  set_Title(Title);
  set_Author(Author);
  set_Isbn(ISBN);
} 


void Book::set_Book(std::string title, std::string author, std::string isbn){
  set_Title(title);
  set_Author(author);
  set_Isbn(isbn);
}

void Book::set_Title(std::string title){
  b_Title = title;
}
void Book::set_Author(std::string author){
  b_Author = author;
}
void Book::set_Isbn(std::string isbn){
  b_ISBN = isbn;
}

std::string Book::get_Title(){
  return b_Title;
}
std::string Book::get_Author(){
  return b_Author;
}
std::string Book::get_Isbn(){
  return b_ISBN;
}

std::string Book::to_string(){
  return "\nTitle: " + b_Title + "\tAuthor: " + b_Author + "\tISBN: " + b_ISBN;
}
