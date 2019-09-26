from test_framework import generic_test


def h_index(citations):
    e = len(citations)
    citations.sort()
    for i in range(0,e):
        if e-i <= citations[i]:
            return e-i
    return 0

if __name__ == '__main__':
    exit(generic_test.generic_test_main("h_index.py", 'h_index.tsv', h_index))
