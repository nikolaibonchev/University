
public class Main {
    public static void main(String[] args) {
        Product[] products = {
                new Product("Spoko", 1.40),
            new Product("Devin", 0.77),
            new Product("Karina", 0.50)};

        Store mag = new Store(products);
        double total = mag.totalPrice();

        System.out.println("The total price of the products is: " + total);
    }
}