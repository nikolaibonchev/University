//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Employee emp = new Employee("Gosho", 1000);
        TeamLeader emp2 = new TeamLeader("Pesho", 2000, 500);
        Programmer emp3 = new Programmer("Marin",2,500,2000);

        double emp1Salary = emp.getYearSalary();
        double emp2Salary = emp2.getYearSalary();
        double emp3Salary = emp3.getYearSalary();

        //System.out.println(emp1Salary);
        //System.out.println(emp2Salary);
        System.out.println(emp3Salary);
    }
}