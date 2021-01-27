def fib1(n):
    global f1
    f1 = f1 + 1
    if n<3:
        return 1
    return fib1(n-1) + fib1(n-2)
    
def fastfib(n, rec):
    global f2
    f2 = f2 + 1
    if n in rec:
        return rec[n]
    rec[n] = fastfib(n-1, rec) + fastfib(n-2, rec)
    return rec[n]
    
def fib2(n):
    rec = {1:1, 2:1}
    return fastfib(n, rec)

f1 = 1
f2 = 1
print("fib(30)", fib1(30), "Calls:", f1)
print("fib(30)", fib2(30), "Calls:", f2)