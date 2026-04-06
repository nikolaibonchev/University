public class Programmer {
    private String name;
    private double salary;
    private double overtime;
    private double hourlyRate;

    public Programmer(String inName, double inHourlyRate, double inOvertime, double inSalary) {
        hourlyRate = inHourlyRate;
        overtime = inOvertime;
        salary = inSalary;
        name = inName;
    }

    double getYearSalary(){
        return salary * 12 + overtime + hourlyRate;
    }
}
