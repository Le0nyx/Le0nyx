package j02_Callable;

import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.*;

public class SorterCallable implements Callable<byte [ ]> {
    private final byte[ ] b;
    SorterCallable( byte[ ] b ) {
        this.b = b;
    }
    @Override public byte[ ] call() {
        Arrays.sort(b);
        return b;
    }

    public static void main( String[] args ) throws ExecutionException, InterruptedException {
        byte[] b = new byte[4000000];
        new Random().nextBytes(b);
        Callable<byte[]> c = new SorterCallable(b);

        ExecutorService executor = Executors.newCachedThreadPool();
        Future<byte[]> result = executor.submit(c);

        byte[] bs = result.get();
        System.out.printf( "%d, %d, %d%n", bs[0], bs[1], bs[bs.length-1] );

        executor.shutdown();
    }
}
