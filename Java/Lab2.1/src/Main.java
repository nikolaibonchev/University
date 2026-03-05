import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter n of matrix: ");
        int n = input.nextInt();
        int[][] matrix = new int[n][n];

        int counter = 1;
        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = counter;
                counter++;
            }
        }

        printMatrix(matrix);
        int[][] reversedMatrix = reverseMatrix(matrix);
        printMatrix(reversedMatrix);

        input.close();
    }

    public static void printMatrix(int[][]matrix){
        for (int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int[][] reverseMatrix(int[][]matrix){
        int[][] newMatrix = new int[matrix.length][matrix.length];
        for (int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix.length; j++){
                newMatrix[i][j] = matrix[matrix.length - 1 - j][i];
            }
        }

        return newMatrix;
    }
}