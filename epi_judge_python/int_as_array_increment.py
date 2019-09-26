from test_framework import generic_test

# Time Complexity: O(n)
# Space Complexity: O(1)
# Avg Run Time: 3ms
def plus_one(A:list):
    for i in reversed(range(0,len(A))):
        A[i] += 1
        if A[i] != 10:
            return A
        A[i] = 0

    A.insert(0,1)
    return A

# Avg Run Time: 12 ms
def TB_sol_plus_one(A) :
    A[-1] += 1
    for i in reversed(range(1, len(A))):
        if A[i] != 10:
            break
        A[i] = 0
        A[i-1] += 1
    if A[0] == 10:
    # There is a carry-out, so we need one more digit to store the resu-It
    # A slick way to do this is to append a 0 at the end of the array,
    # and update the fjrst entry to 1.
        A[0] = 1
        A. append (0)
    return A

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("int_as_array_increment.py",
                                       "int_as_array_increment.tsv", plus_one))
