//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Employer emp = new Employer("Gosho", 1000);
        TeamLeader emp2 = new TeamLeader("Pesho", 2000, 500);

        emp1Salary = emp.getYearSalary();
        emp2Salary = emp2.getYearSalary();

        System.out.println(emp1Salary);
        System.out.println(emp2Salary);
    }
}