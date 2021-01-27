# import matplotlib.pyplot as plt
# plt.plot([1,2,3,4])
# plt.ylabel('some numbers')
# plt.show()

import numpy as np

a = [1,2,3,4]
b = ["Ayush", "Koul", "is", "awesome"]

biases = [np.random.randn(y, 1) for y in a[1:]]
weights = [np.random.randn(y, x) for x, y in zip(a[:-1], a[1:])]

for x in biases:
    print(x)
    # print(y)
# a = []
if a:
    print("yes a")

# a, b = zip
