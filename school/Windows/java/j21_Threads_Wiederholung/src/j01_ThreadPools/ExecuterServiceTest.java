package j01_ThreadPools;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExecuterServiceTest {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();
        RunnableTest test1 = new RunnableTest();

        executor.execute(test1.r1);
        executor.execute(test1.r2);

        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        executor.execute(test1.r1);
        executor.execute(test1.r2);

        executor.shutdown();
    }

}
