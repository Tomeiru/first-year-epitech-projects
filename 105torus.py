##
## EPITECH PROJECT, 2021
## 105torus
## File description:
## 5th project in the math module
##

import sys

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
        return (interval)
    else:
        return (secant(interval, a, n))

def newton(x, a, n):
    fct_x = function(x, a)
    prime_x = prime(x, a)
    x_new = (x - (fct_x/prime_x)) % n
    print("x =", round(x, n))
    if x_new <= pow(10, -n) or x_new - x <= pow(10, -n):
        return (x_new)
    else:
        return (newton(x_new, a, n))

def bisection(interval, a, n):
    c = (interval[0]+interval[1])/2
    fct_a, fct_c = function(interval[0], a), function(c, a)
    if fct_a*fct_c < 0:
        interval[1] = c
    else:
        interval[0] = c
    print("x =", round(c, n))
    if interval[1] - interval[0] <= pow(10, -n):
        return (interval)
    else:
        return (bisection(interval, a, n))

def compare_strings(reference, string):
    count = 0
    for x in range(0, len(reference)):
        if string[x] == reference[x]:
            count += 1
    return (count == len(reference))

def main(opt, a, n):
    if compare_strings("1", opt) == True:
        return (bisection([float(0), float(1)], a, n))
    elif compare_strings("2", opt) == True:
        return (newton(0.5, a, n))
    elif compare_strings("3", opt) == True:
        return (secant([float(0), float(1)], a, n))
    print("./105torus: error: invalid method option given, check usage with -h")
    return (a)

def print_help():
    print("USAGE\n\t./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n\t", end="")
    print("opt\tmethod option:\n\t\t\t1 for the bisection method")
    print("\t\t\t2 for Newton's method\n\t\t\t3 for the secant method")
    print("\ta[0-4]\tcoefficients of the equation\n\tn\tprecision ", end="")
    print("(the application of the polynomial to the solution should ", end="")
    print("be smaller than 10^-n)")

if __name__ == "__main__":
    if len(sys.argv) == 8:
        main(sys.argv[1], [float(sys.argv[2]), float(sys.argv[3]),
        float(sys.argv[4]), float(sys.argv[5]), float(sys.argv[6])],
        int(sys.argv[7]))
    elif len(sys.argv) == 2:
        if compare_strings("-h", sys.argv[1]) == True:
            print_help()
    else:
        print("./105torus: error: invalid number of arguments given, ", end="")
        print("check usage with '-h'")