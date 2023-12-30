/* create a system to manage library catalog .it should have classes for books .you can add author and catalog itself .implement methods for
checking out and returning books , searching for books by title and author.*/
#include<bits/stdc++.h>
using namespace std;
class Book {
public:
    int id;
    string title;
    string author;
    int quantity;

    Book(int i, const string& t, const string& a, int q) : id(i), title(t), author(a), quantity(q){}
    void display() const{
        cout << "ID: " << id << "\tTitle: " << title << "\tAuthor: " << author << "\tQuantity: " << quantity << endl;
    }
};
class LibraryCatalog{
private:
    vector<Book> books;
public:
    void addBook(int id, const string& title, const string& author, int quantity){
        books.emplace_back(id, title, author, quantity);
        cout << "Book added successfully!" << endl;
    }
    void displayBooks() const{
        cout << "Library Catalog:\n";
        for(const Book& book : books){
            book.display();
        }
    }
    void searchByTitle(const string& title) const{
        cout << "Search Results:\n";
        for(const Book& book : books){
            if (book.title == title) {
                book.display();
                return;
            }
        }
        cout << "Book not found.\n";
    }
    void searchByAuthor(const string& author) const{
        cout << "Search Results:\n";
        for(const Book& book : books){
            if(book.author == author){
                book.display();
            }
        }
    }
};
int main(){
    LibraryCatalog library;

    library.addBook(1, "The Catcher in the Rye", "J.D. Salinger", 10);
    library.addBook(2, "To Kill a Mockingbird", "Harper Lee", 8);
    library.addBook(3, "1984", "George Orwell", 15);

    library.displayBooks();

    string searchTitle, searchAuthor;
    cout << "Enter the title to search: ";
    cin >> searchTitle;
    library.searchByTitle(searchTitle);

    cout << "Enter the author to search: ";
    cin >> searchAuthor;
    library.searchByAuthor(searchAuthor);

    return 0;
}