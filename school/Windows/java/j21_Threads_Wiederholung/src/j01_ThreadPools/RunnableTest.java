package j01_ThreadPools;

public class RunnableTest {
    Runnable r1 = new Runnable() {
        @Override public void run() {
            System.out.println( "A1 " + Thread.currentThread() );
            System.out.println( "A2 " + Thread.currentThread() );
        }
    };
    Runnable r2 = new Runnable() {
        @Override public void run() {
            System.out.println( "B1 " + Thread.currentThread() );
            System.out.println( "B2 " + Thread.currentThread() );
        }
    };
}
