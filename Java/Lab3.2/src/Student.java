public class Student {
    String name;
    int[] grades;

    Student(String inName, int[] inGrades){
        name = inName;
        grades = inGrades;
    }

    double avarageGrade(){
        int count = 0;
        double total = 0;
        for (int grade:grades){
            count++;
            total += grade;
        }

        return total / count;
    };
}
