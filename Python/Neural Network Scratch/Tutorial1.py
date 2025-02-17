import numpy as np
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

#4x3 2D array
training_inputs = np.array([[0,0,1],
                            [1,1,1],
                            [1,0,1],
                            [0,1,1]])


#4x1 2D array
training_outputs = np.array([[0,1,1,0]]).T

np.random.seed(1)

#3x1 2D array
weights =  2 * np.random.random((3,1)) - 1

# print(weights)

for i in range(10000):
    input_layer = training_inputs
    outputs = sigmoid(np.dot(input_layer, weights))
    error = training_outputs - outputs
    adjustments = error * sigmoid_derivative(outputs)
    weights += np.dot(input_layer.T, adjustments)

print('Weights:')
[print(a) for a in weights]

print('Outputs: ')
[print(a) for a in outputs]