def euler_phi(n):
    if n <= 0:
        return 0
    phi = n  # Initialize phi to n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            phi -= phi // p
        p += 1
    if n > 1:
        phi -= phi // n
    return phi

if __name__ == "__main__":
    n = int(input("Enter an integer (n) to calculate Euler's Totient Function: "))
    result = euler_phi(n)
    print(f"Phi({n}) = {result}")
