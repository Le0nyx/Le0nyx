package j01_ThreadPools;

public class MainRunnable {
    public static void main(String[] args) {
        RunnableTest test1 = new RunnableTest();

        test1.r1.run();
        test1.r2.run();
    }
}
