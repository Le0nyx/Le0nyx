public class j04_arrays {
    public static void main(String[] args){
        String[] cars = {"Toyota", "Audi", "Honda"};
        System.out.println(cars[0]+", "+cars[1]+", "+cars[2]);

        int size = 10;
        int[] arr = new int[size];
        for(int i = 0;i<size;i++){
            arr[i] = i;
        }

        System.out.println("Array: ");
        for(int i = 0;i<size;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
