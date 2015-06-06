# BlueBook code decryption (Ruby implementation)

def sieve(n)
  # Compute primes using sieve of Eratosthenes
  x = [1] * n
  x[1] = 0
   
  (2...n/2).each do |i|
    j = 2 * i

    while j < n
      x[j] = 0
      j = j + i
    end
  end

  return x
end

def prime(n, x)
  # Find nth prime
  i = 1
  j = 1
  
  while j <= n
      if x[i] == 1
          j = j + 1
      end

      i = i + 1
  end
  
  return i - 1
end

# Compute BlueBook unlock code
x = sieve(10000)

code = [1206, 301, 384, 5]
key = [1, 1, 2, 2]

$stdout.write [73, 83, 66, 78, 32, 61, 32].map! { |i| i = i.chr }.join("")

(0...4).each do |i|
  $stdout.write(prime(code[i], x) - key[i])
end

puts
