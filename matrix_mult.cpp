#include <gtest/gtest.h>
#include "math/matrix.h"
#include "math/load.h"
#include "time/time.h"

// Demonstrate some basic assertions.
TEST(MatrixMultiplication, BasicAssertions) {
  // Arrange
  Matrix<float> a(1000, 1000, true);
  a = loadMatrixFromFile<float>("/home/johny/neural-network/examples/m1000x1000/matrixA.tabseparated");
  Matrix<float> b(1000, 1000, true);
  b = loadMatrixFromFile<float>("/home/johny/neural-network/examples/m1000x1000/matrixB.tabseparated");
  Matrix<float> expectedResultMatrix(1000, 1000, true);
  expectedResultMatrix = loadMatrixFromFile<float>("/home/johny/neural-network/examples/m1000x1000/result.tabseparated");

  // Act (multiplication)
  Matrix<float> c = matrixMultiplier(a, b);
  
  // Assert
  EXPECT_TRUE(compareFloatMatrixes(c, expectedResultMatrix));
}