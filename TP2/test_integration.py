import sys
sys.path.append('src')

import metnum
import numpy as np
import subprocess

# subprocess.run(['make', 'clean'], check=True)

# # Ejecutar `make`
# subprocess.run(['make'], check=True)


N = 10
D = np.diag(range(N, 0, -1))

v = np.ones((D.shape[0], 1))
v = v / np.linalg.norm(v)

# Matriz de Householder
B = np.eye(D.shape[0]) - 2 * (v @ v.T)

M = B.T @ D @ B

print(metnum.power_iteration_deflation(M, 10,niter=5000, epsilon=1e-16))