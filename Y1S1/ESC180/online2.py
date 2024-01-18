def recursive_multiply(a, b):
    return a + recursive_multiply(a, b - 1) if b > 0 else 0

def recursive_power(base, exp):
    return base * recursive_power(base, exp - 1) if exp > 0 else 1

def print_numbers_reverse(n):
    if n >= 0:
        print(n)
        print_numbers_reverse(n - 1)

def print_numbers(n):
    if n >= 0:
        print_numbers(n - 1)
        print(n)

def reverse_string(s):
    return s[-1] + reverse_string(s[:-1]) if s!="" else ""

def is_prime(n, d=2):
    return n >= 2 and (d * d > n or (n % d != 0 and is_prime(n, d + 1)))

def fibonacci(n):
    return 0 if n == 0 else 1 if n == 1 else fibonacci(n - 1) + fibonacci(n - 2)