import java.util.Arrays;

public class j03_selectionsort_recursive {
    public static void main(String[] args){
        int[] arr = {4, 5, 2, 3, 10, 100, 0, 0, 4};

        System.out.println("\nUnsorted array: ");
        print_int_arr(arr);

        selection(arr, arr.length);

        System.out.println("\nSorted array: ");
        print_int_arr(arr);
    }

    static void print_int_arr(int[] arr){
        for (int j : arr) {
            System.out.print(j+", ");
        }
    }

    static void selection(int[] arr, int size){
        if(size == 1) {
            return;
        }
        int index = 0;
        int temp = 0;
        for(int i = 1; i < size; i++){
            if(arr[i] < arr[index]){
                index = i;
            }
        }
        temp = arr[0];
        arr[0] = arr[index];
        arr[index] = temp;

        int[] newarr = Arrays.copyOfRange(arr, 1, arr.length);
        selection(newarr, size - 1);

        System.arraycopy(newarr, 0, arr, 1, newarr.length); //last iteration
    }
}
