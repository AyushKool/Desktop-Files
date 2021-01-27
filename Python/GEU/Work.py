def sort(a, asc=True):
    for i in range(1, len(a)):
        key, j = a[i], i-1

        while j >= 0 and (a[j] > key if asc else a[j] < key):
            a[j + 1] = a[j]
            j = j - 1
        a[j + 1] = key
a = [1, 3, 2, 55, 32, 21, -4, 3]
print("Before sorting:             ", a)
sort(a, asc=True)
print("After sorting (Ascending):  ", a)
sort(a, asc=False)
print("After sorting (Descending): ", a)
