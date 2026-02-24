import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        float i_kg = input.nextFloat();
        float i_height = input.nextFloat();

        float bmi_res = BMI(i_kg, i_height);
        System.out.println("Your BMI is:"+ bmi_res);

        System.out.println("What gender you want to calculate the Ideal Body Weight? ");
        String gender = input.next();

        switch(gender){
            case "Male":
                double idbwMen = idealBodyWeightMen(i_height);
                System.out.println("Result"+ idbwMen);
                break;
            case "Female":
                double idbwWomen = idealBodyWeightWomen(i_kg, i_height);
                System.out.println("Result"+ idbwWomen);
                break;
        }
    }

    public static float BMI(float kg, float height){
        float division = kg / (height*height);
        float result = 10000*division;
        return result;
    }

    public static double idealBodyWeightMen(float height){
        double calcHeight = (height/2.54) - 60;
        return 50 + 2.3*calcHeight;
    }

    public static double idealBodyWeightWomen(float kg, float height){
        float v = kg * kg / height * height;
        double calc = 148 * v;
        return 1.07*kg - calc;
    }
}