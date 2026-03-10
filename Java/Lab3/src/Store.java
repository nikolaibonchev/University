public class Store {
    Product[] products;

    Store(Product[] inProducts){
        products = inProducts;
    }

    double totalPrice(){
        double price = 0;

       for (Product product : products){
            price += product.price;
       }

       return price;
    }
}
