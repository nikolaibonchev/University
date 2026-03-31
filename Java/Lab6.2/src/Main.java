import java.util.TreeSet;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        int[] arr = {4,8,20,24,50,23,1,2};
        TreeSet<Integer> nums = new TreeSet<>();
        for (int num : arr){
            if(num >10 && num % 2 == 0){
                nums.add(num);
            }
        }

        System.out.println(nums);
    }
}