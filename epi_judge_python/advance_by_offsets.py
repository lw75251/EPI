from test_framework import generic_test

# Time Complexity: O(n)
# Space Complexity: O(1)
# Avg Run Time: 46 ms
# Median Run Time: 7 ms

def can_reach_end(A):
    moves = 0
    i = 0
    while i < len(A) and moves >= 0:
        if A[i] > moves:
            moves = A[i]
        moves -= 1
        i += 1
    return i == len(A)

# Avg Run Time: 127 ms
# Median Run Time: 30 ms

# def can_reach_end(A):
#     furthest_reach_so_far, last_index = 0, len(A)-1
#     i = 0
#     while i <= furthest_reach_so_far and furthest_reach_so_far < last_index:
#         furthest_reach_so_far = max(furthest_reach_so_far,A[i]+i)
#         i+=1
#     return furthest_reach_so_far >= last_index

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "advance_by_offsets.py", "advance_by_offsets.tsv", can_reach_end))
