#include <bits/stdc++.h>
#include <eigen3/Eigen/Dense>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

#define forn(i, n) for(int i=0; i<n; i++)

pair<pair<double,VectorXd>, double> power_iteration(const MatrixXd& A, int niter = 10000, double eps= 1e-6) {
    const int m = A.rows();
    VectorXd v(m);
    forn(i,m){
        v[i]=rand();
    }
    double l = 0;
    double error =0;
    forn(i, niter){
        v = A*v;
        v.normalize();
        forn(i,m){
            cout << v[i] << " ";
        }
        cout << '\n';
        l = (v.transpose() * A * v ).value() / (v.transpose() * v).value();
        if((A*v-l*v).norm()<= eps){
            error = (A*v-l*v).squaredNorm();
            break;
        }
        cout << "l:" << " "<< l << '\n';
    }
    l = (v.transpose() * A * v ).value()/ (v.transpose()*v).value();
    return {{l,v}, error};
}

pair<vector<double>, vector<VectorXd>> power_iteration_deflation(MatrixXd A, int num=2, int niter=1000, double eps=1e-6){
    const int m = A.rows();
    const int n = A.cols();
    vector<double> eigenvalues;
    vector<VectorXd> eigenvectors(m);
    VectorXd v(m);
    double l = 0.0;
    forn(i,n){
        MatrixXd A = A - l * (v * v.transpose());
        auto res = power_iteration(A);
        eigenvalues.push_back(res.first.first);
        eigenvectors[i]=res.first.second;
        l = res.first.first;
        v = res.first.second;
    }
    return {eigenvalues, eigenvectors};
}

int main() {
    MatrixXd D(5,5);
    D << 5.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 4.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 3.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 2.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 1.0;
    
    VectorXd v(5);
    v << 1.0, 1.0, 1.0, 1.0, 1.0;
    v.normalize();

    MatrixXd Id(5,5);
    Id << 1.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 1.0;
    MatrixXd H = Id - 2*(v*v.transpose()); 
    cout << H << '\n';
    MatrixXd M = H.transpose() * D * H;
    cout << M << '\n';
    auto res = power_iteration(M);
    cout << "lambda: " << res.first.first << '\n';
    forn(i,5){
        cout << res.first.second(i) << " ";
    }
    return 0;
}