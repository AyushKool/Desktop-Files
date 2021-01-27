import numpy as np


def sigmoid(z):
    return 1/(1 + np.exp(-z))


def sigmoid_prime(z):
    return z * (1 - z)


training_inputs = np.array([[0, 0],
                            [0, 1],
                            [1, 0],
                            [1, 1]])

training_outputs = np.array([[0, 1, 1, 0]]).T

np.random.seed(1)

# Random values from [-1, 1) in 2x1 matrix form
weights = 2 * np.random.random((2, 1)) - 1

# print(training_outputs)

epochs = 100000


# print(weights)

for iteration in range(epochs):
    input_layer = training_inputs
    outputs = sigmoid(np.dot(input_layer, weights))
    error = training_outputs - outputs
    adjustments = error * sigmoid_prime(outputs)
    weights += np.dot(input_layer.T, adjustments)
    # print(outputs)
    # print(adjustments)
    # print(error)
    # print(outputs)
    # print(weights)
    # print(input_layer.T)

# print(weights)
print(outputs)


'''
This Neural Network works as an XOR Logic gate:
    X1  X2      Y
    --------------
    0   0       0
    0   1       1
    1   0       1
    1   1       0
X1, X2 are the inputs and Y is the output
'''