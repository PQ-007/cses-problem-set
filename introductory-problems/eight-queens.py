

def solve_8_queens():
    solutions = []
    board = [-1] * 8
    cols = set()
    pos_diag = set() 
    neg_diag = set() 
    
    def backtrack(row):
        if row == 8:
            solutions.append(board.copy())
            return
        for col in range(8):
            if col in cols or (row + col) in pos_diag or (row - col) in neg_diag:
                continue 
                
            board[row] = col
            cols.add(col)
            pos_diag.add(row + col)
            neg_diag.add(row - col)
            
            backtrack(row + 1)
            
            cols.remove(col)
            pos_diag.remove(row + col)
            neg_diag.remove(row - col)

    backtrack(0)
    return solutions

# 1. Generate all 92 standard solutions
all_solutions = solve_8_queens()

# 2. Read the 8x8 board from user input
# We'll use a set of tuples for O(1) bomb checks
bomb_positions = set()

for i in range(8):
    # Read a line, strip whitespace, and handle characters
    row_input = input().strip()
    for j in range(8):
        if j < len(row_input) and row_input[j] == '*':
            bomb_positions.add((i, j))

# 3. Check each solution against the bomb positions
valid_solution_count = 0


for solution in all_solutions:
    is_valid = True
    
    # Check all 8 queen positions in this specific solution
    for row in range(8):
        col = solution[row]  # The queen is at (row, col)
        
        # If a queen lands on a bomb, this solution is invalid
        if (row, col) in bomb_positions:
            is_valid = False
            break  # No need to check the rest of the rows for this solution
            
    if is_valid:
        valid_solution_count += 1


print(valid_solution_count)
 