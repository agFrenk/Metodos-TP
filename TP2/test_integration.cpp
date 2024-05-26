#include <iostream>
#include <eigen3/Eigen/Dense>
#include <dlfcn.h>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

#define forn(i, n) for(int i=0; i<n; i++)

using namespace Eigen;

extern "C" {
    int easy_sum(int a, int b) {
        return a + b;
    }

    pair<pair<double,VectorXd>, double> power_iteration(const MatrixXd& A, int niter = 10000, double eps= 1e-6) {
        // cout << A << '\n';
        const int m = A.rows();
        VectorXd v(m);
        forn(i,m){
            // volver a ponerle rand()
            v[i]=1;
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
}