import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double x1,y1,x2,y2;
        Scanner sc = new Scanner(System.in);
        x1 = sc.nextDouble();
        y1 = sc.nextDouble();
        x2 = sc.nextDouble();
        y2 = sc.nextDouble();
        System.out.printf("%.4f\n",distance(x1,y1,x2,y2));
        sc.close();
    }

    private static double distance(double x1, double y1, double x2, double y2) {
        return Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
}