//
// Created by Jacques Perrault on 10/2/21.
//
#include <catch2/catch.hpp>
#include <iostream>
#include <Eigen/Dense>
#include <3dMethods/pca.h>
using namespace Eigen;
using namespace std;

SCENARIO("pca", "[utils.cpp]")
{
    MatrixXd mat(3,3);
    mat << 1, 1, 1, -2, -1, -1, 1.2, 1.2, 1.2;
    auto j = Pca(mat);

    cout << "eigenValues:\n" << get<0>(j) << endl;
    cout << "eigen vectors: \n" << get<1>(j) << endl;

}