//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Book b1 = new Book("Mamnik", "Vasil Popov");
        Book b2 = new Book("Metamorphosis", "Frank Kafka");
        Book b3 = new Book("Pod Igoto", "Ivan Vazov");
        Book[] books = {b1, b2, b3};

        Library lib = new Library(books);
        lib.printAuthors();
    }
}