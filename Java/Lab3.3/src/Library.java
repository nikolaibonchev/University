public class Library {
    Book[] books;

    Library(Book[] inBooks){
        books = inBooks;
    }

    void printAuthors(){
        for (int i = 0; i < books.length; i++){
            System.out.println("The Author of Book: "+books[i].title + " is: "+books[i].author);
        }
    }
}
