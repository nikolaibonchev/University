import java.util.Map;

public class Lab1 {
    enum Currency{
        BGN(1.67),
        EUR(0.84),
        GBP(0.73),
        JPY(154.37);
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter price in US Dollar: ");
        float usd = input.nextShort();

        System.out.println("Choose currency: ");
        String valuta = input.next();
        float price = usd * Currency.valuta;

        System.out.println("Your price in %s is %.2f%n", valuta, price);
    }
}
