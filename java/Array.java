public class Array {
    public static void main(String args[]) {
        int a[] = new int[3]; // declare an array of size n
        a[0]=1;
        a[1]=2;
        a[2]=4;
        int n = a.length; // get length of array
        for(int i=0; i<n; i++) {
            System.out.print(a[i]+" ");
        }
    }
}