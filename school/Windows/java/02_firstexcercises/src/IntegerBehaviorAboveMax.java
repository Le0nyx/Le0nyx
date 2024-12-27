public class IntegerBehaviorAboveMax {
    public static void main(String[] args) {
        int x, y, z;
        x = Integer.MAX_VALUE; // gives the max value a integer can store while being signed
        y = x + 1; // goes into the - and upward from there since the integer inst big enough
        z = x * 2; // since the 0 is in the positive multipling causes it to go -1 each multiplication and also the max value gets from the positive added onto the negative

        System.out.println(x+ " "+y+ " "+ z);
    }
}
