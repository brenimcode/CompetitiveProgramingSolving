import java.io.IOException;
import java.util.Scanner;
 
public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int vet[] = new int[3];
        for(int i = 0;i < 3;++i)
            vet[i] = scanner.nextInt();
        int maior = vet[0];
        for(int i = 1;i < 3;++i)
            if(vet[i] > maior)
                maior = vet[i];

        System.out.println(maior + "eh o maior");
        scanner.close();
    }
 
}