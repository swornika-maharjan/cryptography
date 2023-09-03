def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def is_primitive_root(g, p):
    if gcd(g, p) != 1:
        return False

    # Calculate Euler's Totient Function for p
    phi = p - 1

    # Find all prime factors of phi
    prime_factors = set()
    temp_phi = phi
    for i in range(2, int(phi**0.5) + 1):
        while temp_phi % i == 0:
            prime_factors.add(i)
            temp_phi //= i
    if temp_phi > 1:
        prime_factors.add(temp_phi)

    # Check if g^((p-1)/q) is not congruent to 1 mod p for each prime factor q of phi
    for q in prime_factors:
        if pow(g, phi // q, p) == 1:
            return False

    return True

def find_primitive_roots(p):
    primitive_roots = []
    for g in range(2, p):
        if is_primitive_root(g, p):
            primitive_roots.append(g)
    return primitive_roots

if __name__ == "__main__":
    p = int(input("Enter a prime number (p): "))
    primitive_roots = find_primitive_roots(p)

    if len(primitive_roots) == 0:
        print(f"There are no primitive roots modulo {p}.")
    else:
        print(f"Primitive roots modulo {p} are: {primitive_roots}")
