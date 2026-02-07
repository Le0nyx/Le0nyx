package j03_PrimeNumberChecker;

import java.util.concurrent.Callable;

public class PZPruefer implements Callable<Boolean> {
    private long num;

    public PZPruefer(long x){ num = x; }

    private Boolean checkIsPrime(long n){
        if (n < 2) return false;
        if (n % 2 == 0 && n != 2) return false;
        long grenze = (long) Math.sqrt(n);
        for (long i = 3; i <= grenze; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    @Override
    public Boolean call() throws Exception { return checkIsPrime(num); }
}
