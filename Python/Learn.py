# def fib(n):
# 	a,b = 0,1
# 	while n:
# 		print(a, end = ", ")
# 		a,b = b, a+b
# 		n=n-1
# fib(4)#send int(input("enter limit: "))

board = [[2, 0, 1], 
         [0, 0, 0], 
         [1, 1, 1]]

def show(r, c, display=True):
    try:
        board[r][c] = 1
        if display:
            for i, row in enumerate(board):
                print(i, row)
    except IndexError as e:
        print("\nSomething went Wrong!", e)
    except Exception as e:
        print(e)
'''
var = "My", "Name", "is", "Ayush"  # or put inside ()
for word in var[:-1]:
    print(word, end = " ")
'''

def win(game):
    #Horizontally
    for row in game:
        if row.count(row[0]) == len(row) and row[0] != 0:
            print(f"Player {row[0]} is the winner!")
            return

    #Vertically
    for col in range(len(game)):
        check = []
        for row in game:
            check.append(row[col])
        if check.count(check[0]) == len(check) and check[0] != 0:
            print(f"Player {check[0]} is the winner!")
            return
    
    #Diagonally
    check = [[], []]
    for i in range(len(game)):
        check[0].append(game[i][i])
        check[1].append(game[i][len(game)-i-1])

    if check[0].count(check[0][0]) == len(check[0]) and check[0][0] != 0:
        print(f"Player {check[0][0]} is the winner!")
        return
    if check[1].count(check[1][0]) == len(check[1]) and check[1][0] != 0:
        print(f"Player {check[1][0]} is the winner!")
        return

# i = 0
# for row in board:
#     print(i, row)
#     i += 0
# print('\n')

# x = show
# x(0,0)
# win(board)

# #look at zip function (built-in)

# l = [1, 2, 3, 4, 5]
# print(l[1])

#Flip between 1 and 0:
choice = 0
for i in range(10):
    print(choice+1)
    choice ^= 1
#iterators vs iterable in python 13th video --> itertools (cycle), iter(), next()...
#list comprehension

print("   " + " ".join([str(i) for i in range(3)]))
size = 5
game = [[0 for i in range(size)] for i in range(size)]
print(game)
