#include <gtest/gtest.h>
#include "math/matrix.h"
#include "math/load.h"
#include "time/time.h"

TEST(MatrixCreation, BasicAssertions) {
  // Arrange & Act
  Matrix<unsigned char> a(2, 3, true);
  // Assert
  EXPECT_TRUE(a._rows == 2 && a._cols == 3);
}

TEST(MatrixMultiplication, BasicAssertions) {
  // Arrange
  Matrix<float> a(1000, 1000, true);
  a = load::MatrixFromFile<float>("/home/johny/neural-network/examples/m1000x1000/matrixA.tabseparated");
  Matrix<float> b(1000, 1000, true);
  b = load::MatrixFromFile<float>("/home/johny/neural-network/examples/m1000x1000/matrixB.tabseparated");
  Matrix<float> expectedResultMatrix(1000, 1000, true);
  expectedResultMatrix = load::MatrixFromFile<float>("/home/johny/neural-network/examples/m1000x1000/result.tabseparated");

  // Act (multiplication)
  Matrix<float> c = MatrixMultiplier(a, b);
  
  // Assert
  EXPECT_TRUE(compareFloatMatrixes(c, expectedResultMatrix));
}
