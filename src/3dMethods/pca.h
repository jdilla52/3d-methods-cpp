//
// Created by Jacques Perrault on 10/2/21.
//

#ifndef LAMBDARUNNER_PCA_H
#define LAMBDARUNNER_PCA_H

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;


/// perform pca on a matrix of data
/// page 52
/// \param mat
/// \return eigenValues, eigenVectors
tuple<VectorXd, MatrixXd> Pca(MatrixXd mat) {
  try {
    // 1. Compute the center of mass of the data points,
    // 2. Translate all the points so that the origin is at m:
    MatrixXd centered = mat.rowwise() - mat.colwise().mean();
    // 3. Construct the d  d scatter matrix S = Y Y >, where Y is the  matrix whose columns are the yi
    MatrixXd cov = (centered.adjoint() * centered) / double(mat.rows() - 1);
    //4. Compute the spectral decomposition: S = V V >.  5. Sort the eigenvalues in decreasing order: 1  2 
    SelfAdjointEigenSolver<MatrixXd> eigensolver(cov);
    if (eigensolver.info() != Success) throw runtime_error("failed to solve");

    VectorXd eigen_values = eigensolver.eigenvalues();
    MatrixXd eigen_vectors = eigensolver.eigenvectors();

    // sort values and vectors - pretty hacky I wish this was in eigen...
    std::vector<std::tuple<float, VectorXd>> eigen_vectors_and_values;

    for (int i = 0; i < eigen_values.size(); i++) {
      std::tuple<float, VectorXd> vec_and_val(eigen_values[i], eigen_vectors.row(i));
      eigen_vectors_and_values.push_back(vec_and_val);
    }
    std::sort(eigen_vectors_and_values.begin(), eigen_vectors_and_values.end(),
              [&](const std::tuple<float, VectorXd> &a, const std::tuple<float, VectorXd> &b) -> bool {
                return std::get<0>(a) > std::get<0>(b);
              });

    // replace existing matrices with sorted values
    for (int i = 0; i < eigen_vectors_and_values.size(); i++) {
      auto cur = eigen_vectors_and_values[i];
      eigen_values[i] = std::get<0>(cur);
      eigen_vectors.row(i) = std::get<1>(cur);
    }
    tuple<VectorXd, MatrixXd> final(eigen_values, eigen_vectors);
    return final;
  } catch (exception &e) {
    throw e;
  }
}

#endif //LAMBDARUNNER_PCA_H
