public class TeamLeader extends Employee{
    private double bonus;

    public TeamLeader(String inName, double inSalary, double inBonus){
        super(inName, inSalary);
        bonus = inBonus;
    }

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    double getYearSalary(){
        return getSalary()*12+bonus;
    }
}