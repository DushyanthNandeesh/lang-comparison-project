public class Bench {
    public static void main(String[] args) {
        int n = 5_000_000;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = i;
        long sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        arr = null;
        System.out.println("sum=" + sum);
    }
}
