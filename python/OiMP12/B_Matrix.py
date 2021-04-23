from sys import stdin
from copy import deepcopy


class Matrix:
    def __init__(self, mtrx):
        self.matrix = deepcopy(mtrx)

    def __str__(self):
        return '\n'.join(
            '\t'.join(
                map(
                    str,
                    row
                )
            )
            for row in self.matrix
        )

    def size(self):
        return len(self.matrix), len(self.matrix[0])

    def __add__(self, other):
        resMtrx = []
        n, m = self.size()
        for i in range(n):
            row = []
            for j in range(m):
                row.append(self.matrix[i][j] + other.matrix[i][j])
            resMtrx.append(row)
        return Matrix(resMtrx)

    def __mul__(self, alpha):
        resMtrx = []
        n, m = self.size()
        for i in range(n):
            row = []
            for j in range(m):
                row.append(self.matrix[i][j] * alpha)
            resMtrx.append(row)
        return Matrix(resMtrx)

    __rmul__ = __mul__


exec(stdin.read())
