from sys import stdin
from copy import deepcopy


class MatrixError(BaseException):
    def __init__(self, mtrx1, mtrx2):
        self.matrix1 = mtrx1
        self.matrix2 = mtrx2


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
        n_self, m_self = self.size()
        n_other, m_other = other.size()
        if n_self == n_other and m_self == m_other:
            for i in range(n_self):
                row = []
                for j in range(m_self):
                    row.append(self.matrix[i][j] + other.matrix[i][j])
                resMtrx.append(row)
        else:
            raise MatrixError(self, other)
        return Matrix(resMtrx)

    def __mul__(self, alpha):
        if isinstance(alpha, int) or isinstance(alpha, float):
            resMtrx = []
            n, m = self.size()
            for i in range(n):
                row = []
                for j in range(m):
                    row.append(self.matrix[i][j] * alpha)
                resMtrx.append(row)
            return Matrix(resMtrx)
        elif isinstance(alpha, Matrix):
            if alpha.size()[0] == self.size()[1]:
                resMtrx = []
                n, m = self.size()
                m, k = alpha.size()
                sumEl = 0
                for i in range(n):
                    row = []
                    for j in range(k):
                        for t in range(m):
                            sumEl += self.matrix[i][t] * alpha.matrix[t][j]
                        row.append(sumEl)
                        sumEl = 0
                    resMtrx.append(row)
                return Matrix(resMtrx)
            else:
                raise MatrixError(self, alpha)

    __rmul__ = __mul__

    def transpose(self):
        resMtrx = []
        for row in zip(*self.matrix):
            resMtrx.append(row)
        self.matrix = resMtrx
        return self

    def transposed(mtrx):
        resMtrx = Matrix(mtrx.matrix).transpose()
        return resMtrx


exec(stdin.read())
