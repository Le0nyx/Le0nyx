package j03_PrimeNumberChecker;

import java.util.Arrays;
import java.util.concurrent.Future;

public class Main {
    public static void main(String[] args) throws Exception {
        StoragePrime service = new StoragePrime(4);

        long[] testArray = {3, 4, 96931, 98773, 1000003, 10000019, 2147483647L, 100000000003L};

        for (long z : testArray) {
            Future<Boolean> f = service.checkIsPrime(z);
            System.out.println(z + " ist Prim? " + f.get());
        }

        Boolean[] ergebnisse = service.checkArray(testArray);

        System.out.println("Array-Ergebnisse:");
        System.out.println(Arrays.toString(ergebnisse));

        service.shutdown();
    }
}
