#pragma once

#include <Eigen/Sparse>
#include <Eigen/Dense>
#include <iostream>
#include <utility>
#include <vector>

using Eigen::MatrixXd;
using Eigen::VectorXd;

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrix;
typedef Eigen::SparseMatrix<double> SparseMatrix;
typedef Eigen::VectorXd Vector;
typedef Eigen::VectorXi IVector;

using namespace std;

#define forn(i, n) for(int i=0; i<n; i++)

pair<pair<double, VectorXd>,  pair<double, int>> power_iteration(const Matrix& mat, unsigned niter=5000, double eps=1e-16);
tuple<vector<double>, vector<VectorXd>, vector<double>, vector<int>> power_iteration_deflation(const Matrix& mat, int num=2, int niter=1000, double eps=1e-6);
