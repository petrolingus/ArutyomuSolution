#include <iostream>
#include <iomanip>
#include <random>

using std::size_t;

double **create(size_t, size_t);

void print(double const *const *, size_t, size_t);

double **transform(double const *const *, size_t, size_t, size_t, size_t);

int main() {

    // Size of matrix MxN
    const size_t M = 3;
    const size_t N = 5;

    // Create matrix
    double **matrix = create(M, N);

    // First print of matrix
    print(matrix, M, N);

    // Transform the matrix
    double **transformedMatrix = transform(matrix, M, N, 1, 2);

    std::cout << "\n";
    print(matrix, M, N);

    // Second print of matrix
    std::cout << "\n";
    print(transformedMatrix, M - 1, N - 1);

    // Cleanup matrix
    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

double **create(const size_t M, const size_t N) {
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    auto **matrix = new double *[M];
    for (size_t i = 0; i < M; ++i) {
        matrix[i] = new double[N];
        for (size_t j = 0; j < N; ++j) {
            matrix[i][j] = std::generate_canonical<double, 10>(gen);
        }
    }
    return matrix;
}

void print(double const *const *const matrix, const size_t M, const size_t N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::fixed << std::setprecision(4) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

double **transform(double const *const *const mat, const size_t M, const size_t N, const size_t row, const size_t col) {
    double **result = create(M - 1, N - 1);
    for (size_t i = 0; i < M - 1; ++i) {
        size_t r = (i < row) ? i : i + 1;
        for (size_t j = 0; j < N - 1; ++j) {
            size_t c = (j < col) ? j : j + 1;
            result[i][j] = mat[r][c];
        }
    }
    return result;
}
