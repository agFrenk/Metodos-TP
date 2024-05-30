#include "test_integration.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

#define forn(i, n) for(int i=0; i<n; i++)

pair<pair<double, VectorXd>, pair<double, int>> power_iteration(const Matrix& A, unsigned niter, double eps) {
    const int m = A.rows();
    VectorXd v(m);
    forn(i, m) {
        v[i] = rand();
    }
    double l = 0;
    double error = 0;
    int iter = niter;
    forn(i, niter) {
        v = A * v;
        v.normalize();
        l = (v.transpose() * A * v).value() / (v.transpose() * v).value();
        if ((A * v - l * v).lpNorm<Eigen::Infinity>() <= eps) {
            error = (A * v - l * v).squaredNorm();
            iter = i+1;
            break;
        }
    }
    
    l = (v.transpose() * A * v).value() / (v.transpose() * v).value();
    return {{l, v},  {error, iter}};
}

MatrixXd convert_and_transpose(vector<VectorXd> v, int  n,int m){
    MatrixXd A(n,m);
    forn(i, n){
        forn(j,m){
            A(i,j)=v[i][j];
        }
    } 
    return A.transpose();
}

tuple<vector<double>, MatrixXd, vector<double>, vector<int>> power_iteration_deflation(const Matrix& A, int num, int niter, double eps) {
    Matrix A_copy = A;
    const int m = A.rows();
    vector<double> eigenvalues;
    vector<VectorXd> eigenvectors(num, VectorXd(m));
    VectorXd v(m);
    double l = 0.0;
    vector<double> errors;
    vector<int> iters;
    forn(i, num) {
        auto res = power_iteration(A_copy, niter, eps);
        eigenvalues.push_back(res.first.first);
        eigenvectors[i] = res.first.second;
        errors.push_back(res.second.first);
        iters.push_back(res.second.second);
        l = res.first.first;
        v = res.first.second;
        A_copy = A_copy - l * (v * v.transpose());
    }
    
    return {eigenvalues, convert_and_transpose(eigenvectors, eigenvectors.size(), eigenvectors[0].size()), errors, iters};
}


