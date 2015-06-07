// BlueBook code decryption (Go implementation)

package main

import (
    "fmt"
    "strings"
)

// Compute primes using sieve of Eratosthenes
func sieve(n int) []int {
    x := make([]int, n)
    for i, _ := range x {
        x[i] = 1
    }
    x[1] = 0

    for i := 2; i < n/2; i++ {
        j := 2 * i

        for j < n {
            x[j] = 0
            j = j + i
        }
    }

    return x
}

// Find nth prime
func prime(n int, x []int) int {
    i := 1
    j := 1

    for j <= n {
        if x[i] == 1 {
            j++
        }
        i++
    }

    return i - 1
}

// Compute BlueBook unlock code
func main() {
    x := sieve(10000)

    code := []int {1206, 301, 384, 5}
    key := []int {1, 1, 2, 2}

    c := []int {73, 83, 66, 78, 32, 61, 32}
    d := [7]string {}
    for i, char := range c { d[i] = string(char) }
    fmt.Print(strings.Join(d[:], ""))

    for i := 0; i < 4; i++ {
        fmt.Print(prime(code[i], x) - key[i])
    }

    fmt.Println()
}
