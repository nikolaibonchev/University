public class Employee {
    private String name;
    private double salary;

    public Employee(String inName, double inSalary){
        name = inName;
        salary = inSalary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    double getYearSalary(){
        return salary*12;
    }
}