import java.util.Arrays;
import java.util.Scanner;

public class StatistikCode {

    static int biggest(int[] arr){
        return arr[arr.length-1];
    }

    static int smallest(int[] arr){
        return arr[0];
    }

    static int median(int[] arr){
        return arr[arr.length/2];
    }

    static double aritMittel(int[] arr){
        int total = 0;
        for(int i=0; i<arr.length; i++){ total += arr[i]; }
        return (double) total/arr.length;
    }



    public static void main(String[] args) {
        Scanner inputIG = new Scanner(System.in);

        int input = 1;
        int count = 0;
        int array_size = 5;
        int[] arr = new int[array_size];

        while(input > 0){
            System.out.println("Please Enter value: ");
            input = inputIG.nextInt();

            if(input > 0){ // leave array if negative num
                arr[count] = input;
                count++;

                if(count == array_size-1){ // if array is too small
                    int[] temp = new int[array_size];
                    System.arraycopy(arr, 0, temp, 0, array_size);
                    arr = new int[array_size+5];
                    System.arraycopy(temp, 0, arr, 0, array_size);
                    array_size += 5;
                }
            }
        }

        // output
        // remove remaining 0, count is the actual num of numbers
        int num_start = 0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>0){
                num_start = i;
                break;
            }
        }
        int[] arr2 = new int[count];
        System.arraycopy(arr, num_start, arr2, 0, count);

        Arrays.sort(arr2);
        System.out.println("Smallest Number: "+ smallest(arr2));
        System.out.println("Greatest Number: "+ biggest(arr2)); // because 0 is start
        System.out.println("Median is: "+ median(arr2));
        System.out.println("Arithmetical value is: "+ aritMittel(arr2));

        inputIG.close();
    }
}
