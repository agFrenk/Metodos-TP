import ctypes
import numpy as np
import os

# Borrar el archivo .so si existe
if os.path.exists("test_integration.so"):
    os.remove("test_integration.so")

# Compilar el archivo cpp
os.system("g++ -shared -fPIC -o test_integration.so test_integration.cpp")

# Listar los archivos en el directorio actual
# os.system("ls")


class VectorXd(ctypes.Structure):
    _fields_ = [("data", ctypes.POINTER(ctypes.c_double)),
                ("size", ctypes.c_int)]

class Pair(ctypes.Structure):
    _fields_ = [("first", ctypes.c_double),
                ("second", VectorXd)]

class OuterPair(ctypes.Structure):
    _fields_ = [("first", Pair),
                ("second", ctypes.c_double)]


class sharedlib():
    dlclose = ctypes.CDLL(None).dlclose  # This WON'T work on Win
    dlclose.argtypes = (ctypes.c_void_p,)

    def __init__(self, path, method, *args):
        self.lib = ctypes.cdll.LoadLibrary(f'./{path}')

        # Se explicitan los tipos de los argumentos para el método deseado
        self.method_object = getattr(self.lib, method)
        self.method_object.argtypes = args

    def __call__(self, *args):
        return self.method_object(*args)

    def unload(self):
        while self.dlclose(self.lib._handle)!=-1:
            pass

lib = sharedlib('test_integration.so', 'power_iteration',
                                                            ctypes.POINTER(ctypes.c_double), 
                                                            ctypes.c_int, 
                                                            ctypes.c_double   
                                                            )


#falta crear los datos

N = 10
D = np.diag(range(N, 0, -1))

v = np.ones((D.shape[0], 1))
v = v / np.linalg.norm(v)

# Matriz de Householder
B = np.eye(D.shape[0]) - 2 * (v @ v.T)

M = B.T @ D @ B
niter = 100
epsilon = ctypes.c_double(1e-6)
# Llamamos a nuestra función en C++ pasando los argumentos de entrada
res = lib(
    M.ctypes.data_as(ctypes.POINTER(ctypes.c_double)),
    ctypes.c_int(niter),
    epsilon
)

lib.unload() # para poder recompilar la lib hay que cerrarla