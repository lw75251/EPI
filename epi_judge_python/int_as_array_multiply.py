from test_framework import generic_test


def multiply(num1, num2):
    sign = -1 if (num1[0] < 0) ^ (num2[0] < 0) else 1
    num1[0], num2[0] = abs(num1[0]), abs(num2[0])

    result = [0] * (len(num1) + len(num2))
    for i in reversed(range(len(num1))):
        for j in reversed(range(len(num2))):
            result[i+j+1] += num1[i] * num2[j]
            result[i+j] += result[i+j+1] // 10
            result[i+j+1] %= 10

    i = 0
    while i < len(result) and result[i] == 0:
        i+= 1

    result = [0] if i == len(result) else result[i:]

    return [sign * result[0]] + result[1:]

# def multiply(num1, num2):
#     sign = -1 if ( num1[0] < 0 ) ^ (num2[0] < 0) else 1
#     num1[0], num2[0] = abs(num1[0]), abs(num2[0])

#     result = [0] * (len(num1) + len(num2))
#     for i in reversed(range(len(num1))):
#         for j in reversed(range(len(num2))):
#             result[i+j+1] += num1[i] * num2[j]
#             result[i+j] += result[i+j+1] // 10
#             result[i+j+1] %= 10
    
#     result = result[next((i for i, x in enumerate(result)
#                          if x != 0), len(result)):] or [0]
    
#     return [sign * result[0]] + result[1:]

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("int_as_array_multiply.py",
                                       'int_as_array_multiply.tsv', multiply))
