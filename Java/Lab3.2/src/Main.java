//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Student studA = new Student("Ivan", new int[]{4, 5, 6, 3, 4});
        Student studB = new Student("Pesho", new int[]{3,5,5,6,4});
        Student studC = new Student("Muncho", new int[]{3,4,3,4,2,2});

        double avgA = studA.avarageGrade();
        double avgB = studB.avarageGrade();
        double avgC = studC.avarageGrade();

        System.out.println("The avarage grade of StudA is: " +avgA);
        System.out.println("The avarage grade of StudB is: " +avgB);
        System.out.println("The avarage grade of StudC is: " +avgC);
    }
}