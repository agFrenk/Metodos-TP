#include <bits/stdc++.h>
#include <eigen3/Eigen/Dense>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

#define forn(i, n) for(int i=0; i<n; i++)



pair<double,VectorXd> power_iteration(const MatrixXd& A, int niter = 10000, double eps= 1e-6) {
    const int m = A.rows();
    VectorXd v(m);
    forn(i,m){
        v[i]=1;
    }
    double l;
    forn(i, niter){
        v = A*v;
        v.normalize();
        l = (double)(v.transpose() * A * v ) / (double)(v.transpose()*v);
        if((A*v-l*v).norm()<= tol){
            double error = (A*v-l*v).squaredNorm();
            break;
        }
    }
    l = (double)(v.transpose() * A * v )/ (double)(v.transpose()*v);
    return {l,v};
}

pair<VectorXd, MatrixXd> eigen(MatrixXd A, int num=2, int niter=1000, double eps=1e-6){
    const int m = A.rows();
    const int n = A.cols();
    VectorXd eigenvalues;
    MatrixXd eigenvectors(m,n);
    VectorXd v(m);
    double l = 0.0;
    forn(i,m){
        v[i]=1;
    }
    forn(i,n){
        MatrixXd B = A - l * (v * v.transpose());
        pair<double, VectorXd> res = power_iteration(B);
        eigenvalues.push_back(res.first);
        eigenvectors[i]=(res.second);
        l = res.first;
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
    D << 1.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 1.0;
    MatrixXd H = Id - 2*v*v.transpose(); 
    MatrixXd M = H.transpose() * D * H;

    pair<double, VectorXd> res = power_iteration(M);
    cout << "lambda: " << res.first << '\n';
    forn(i,5){
        cout << res.second(i) << " ";
    }
    return 0;
}