// BlueBook code decryption (Java implementation)

import java.util.Arrays;

class BlueBook {

    // Compute primes using sieve of Eratosthenes
    private static int[] sieve(int n) {
        int[] x = new int[n];
        Arrays.fill(x, 1);
        x[1] = 0;

        for (int i = 2; i < n/2; i++) {
            int j = 2 * i;

            while (j < n) {
                x[j] = 0;
                j = j + i;
            }
        }

        return x;
    }

    
    // Find nth prime
    private static int prime(int n, int[] x) {
        int i = 1;
        int j = 1;

        while (j <= n) {
            if (x[i] == 1) {
                j++;
            }
            i++;
        }

        return i - 1;
    }

    public static void main(String[] args) {
        int[] x = sieve(10000);
        int[] code = new int[] {1206, 301, 384, 5};
        int[] key = new int[] {1, 1, 2, 2};

        for (int i : new int[] {73, 83, 66, 78, 32, 61, 32}) {
            System.out.print((char) i);
        }

        for (int i = 0; i < 4; i++) {
            System.out.print(prime(code[i], x) - key[i]);
        }

        System.out.println();
    }
}
