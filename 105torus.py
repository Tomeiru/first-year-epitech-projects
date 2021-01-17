##
## EPITECH PROJECT, 2021
## 105torus
## File description:
## 5th project in the math module
##

import sys
from sys import stderr

def prime(x, a):
    return (4*a[4]*pow(x, 3) + 3*a[3]*pow(x, 2) + 2*a[2]*x + a[1])

def function(x, a):
    return (a[4]*pow(x, 4) + a[3]*pow(x, 3) + a[2]*pow(x, 2) + a[1]*x + a[0])

def secant(interval, a, n):
    x0 = interval[0]
    x1 = interval[1]
    fct_x0 = function(interval[0], a)
    fct_x1 = function(interval[1], a)
    x_new = x1 - (fct_x1*(x1 - x0)/(fct_x1 - fct_x0))
    interval[0], interval[1] = x1, x_new
    print("x =", round(x_new, n))
    if x_new - x1 <= pow(10, -n) and x1 - x_new <= pow(10, -n):
        sys.exit(84)
    else:
        secant(interval, a, n)

def newton(x, a, n):
    fct_x = function(x, a)
    prime_x = prime(x, a)
    x_new = (x - (fct_x/prime_x)) % n
    print("x =", round(x, n))
    if x_new <= pow(10, -n) or x_new - x <= pow(10, -n):
        sys.exit(0)
    else:
        newton(x_new, a, n)

def bisection(interval, a, n):
    i = 0
    c = (interval[0]+interval[1])/2
    fct_a, fct_c = function(interval[0], a), function(c, a)
    if fct_a*fct_c < 0:
        i = interval[1]
        interval[1] = c
    else:
        i = interval[0]
        interval[0] = c
    print("x =", round(c, n))
    if c - i <= pow(10, -n) and i - c <= pow(10, -n):
        sys.exit(0)
    else:
        bisection(interval, a, n)

def compare_strings(reference, string):
    count = 0
    for x in range(0, len(string)):
        if string[x] == reference[x]:
            count += 1
    return (count == len(reference))

def main(opt, a, n):
    if compare_strings("1", opt) == True:
        return bisection([float(0), float(1)], a, n)
    elif compare_strings("2", opt) == True:
        return newton(0.5, a, n)
    elif compare_strings("3", opt) == True:
        return secant([float(0), float(1)], a, n)
    print("./105torus: error: invalid method ", end="", file=stderr)
    print("option given, check usage with -h", file=stderr)
    sys.exit(84)

def print_help():
    print("USAGE\n\t./105torus opt a0 a1 a2 a3 a4 n\n\n", end="", file=stderr)
    print("DESCRIPTION\n\topt\tmethod option:\n\t\t\t1 ", end="", file=stderr)
    print("for the bisection method\t\t\t2 for Newton's method", file=stderr)
    print("\t\t\t3 for the secant method\n\ta[0-4]\t", end="", file=stderr)
    print("coefficients of the equation\n\tn\tprecision ", end="", file=stderr)
    print("(the application of the polynomial to the ", end="", file=stderr)
    print("solution should be smaller than 10^-n)", file=stderr)
    return (84)

if __name__ == "__main__":
    if len(sys.argv) == 8:
        main(sys.argv[1], [float(sys.argv[2]), float(sys.argv[3]),
        float(sys.argv[4]), float(sys.argv[5]), float(sys.argv[6])],
        int(sys.argv[7]))
    elif len(sys.argv) == 2 and compare_strings("-h", sys.argv[1]) == True:
        print_help()
        sys.exit(84)
    else:
        print("./105torus: error: invalid number ", end="", file=stderr)
        print("of arguments given, check usage with '-h'", file=stderr)
        sys.exit(84)