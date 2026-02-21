import java.util.Scanner; // 1. Трябва ти Scanner, не Map

public class Lab1 {

    enum Currency {
        BGN(1.67),
        EUR(0.84),
        GBP(0.73),
        JPY(154.37);

        // 2. ПОПРАВКА: Трябва да дефинираш променлива, която да пази курса
        final double rate;

        // 3. ПОПРАВКА: Трябва конструктор, който да приеме числото от скобите горе
        Currency(double rate) {
            this.rate = rate;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter price in US Dollar: ");
        // 4. ПОПРАВКА: nextShort() е за малки цели числа. Пари се четат с double.
        double usd = input.nextDouble();

        System.out.println("Choose currency (BGN, EUR, GBP, JPY): ");
        String valutaName = input.next(); // Четем текста, напр. "BGN"

        // 5. ПОПРАВКА: Превръщане на Текст -> Enum
        // Currency.valuta не работи, защото нямаш валута с име "valuta".
        // valueOf() е магията, която намира правилния Enum по името му.
        Currency selected = Currency.valueOf(valutaName);

        // 6. ПОПРАВКА: Използваме полето .rate, което дефинирахме горе
        double price = usd * selected.rate;

        // 7. ПОПРАВКА: println -> printf (за да работят %s и %.2f)
        System.out.printf("Your price in %s is %.2f%n", valutaName, price);
    }
}