from collections import deque

def is_valid_move(state, pos, move):
    """ Check if a move is valid. """
    if move == -1:
        # Move left
        return pos > 0 and state[pos-1] != state[pos]
    elif move == 1:
        # Move right
        return pos < len(state) - 1 and state[pos+1] != state[pos]
    elif move == -2:
        # Jump left
        return pos > 1 and state[pos-2] != state[pos] and state[pos-1] != state[pos]
    elif move == 2:
        # Jump right
        return pos < len(state) - 2 and state[pos+2] != state[pos] and state[pos+1] != state[pos]
    return False

def get_next_states(state):
    """ Get all possible next states from the current state. """
    next_states = []
    empty_pos = state.find('0')
    moves = [-1, 1, -2, 2]  # Left, Right, Jump left, Jump right

    for move in moves:
        if is_valid_move(state, empty_pos, move):
            new_pos = empty_pos + move
            new_state = list(state)
            new_state[empty_pos], new_state[new_pos] = new_state[new_pos], new_state[empty_pos]
            next_states.append("".join(new_state))

    return next_states

def find_solution(start_state, end_state):
    """ Find the solution using Breadth-First Search. """
    queue = deque([(start_state, [start_state])])  # State and path
    visited = set()

    while queue:
        current_state, path = queue.popleft()
        if current_state == end_state:
            return path  # Found the solution

        for next_state in get_next_states(current_state):
            if next_state not in visited:
                visited.add(next_state)
                queue.append((next_state, path + [next_state]))

    return None  # No solution found

# Starting state and ending state
start_state = "BBB0NNN"
end_state = "NNN0BBB"

# Find the solution
solution = find_solution(start_state, end_state)

print(solution)