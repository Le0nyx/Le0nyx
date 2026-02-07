package j03_PrimeNumberChecker;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

public class StoragePrime{
    private final ExecutorService pool;

    public StoragePrime(int threads) {
        this.pool = Executors.newFixedThreadPool(threads);
    }

    public Future<Boolean> checkIsPrime(long zahl) {
        return pool.submit(new PZPruefer(zahl));
    }


    public Boolean[] checkArray(long[] zahlen) throws InterruptedException, ExecutionException {
        List<Future<Boolean>> futures = new ArrayList<>();
        for (long z : zahlen) { futures.add(checkIsPrime(z)); }
        Boolean[] ergebnisse = new Boolean[zahlen.length];

        for (int i = 0; i < zahlen.length; i++) {
            ergebnisse[i] = futures.get(i).get();
        }
        return ergebnisse;
    }


    public void shutdown() {
        pool.shutdown();
    }
}
