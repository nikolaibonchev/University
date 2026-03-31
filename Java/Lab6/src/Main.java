import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        String text = "cat|dog|monkey|elephant|gorilla";
        Set<String> set1 = new HashSet<>();
        String[] animals = text.split("\\W+");
        set1.addAll(Arrays.asList(animals));

        System.out.println(set1);
    }
}