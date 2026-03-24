//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Pair pair = new Pair();
        Pair pair2 = new Pair();
        Pair pair3 = new Pair();

        pair.setA("KST");
        String specialty = (String) pair.getA();
        pair.setB(235);
        int number = (int) pair.getB();

        pair2.setA("Conco");
        String name = (String) pair2.getA();
        pair2.setB(95903089L);
        long egn = (long) pair2.getB();

        pair3.setA("Morkov");
        String vegetable = (String) pair3.getA();
        pair3.setB("Orange");
        String color = (String) pair3.getA();

        pair.printPair();
        pair2.printPair();
        pair3.printPair();
    }
}