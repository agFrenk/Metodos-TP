import sys
import numpy as np


#Punto 1
a_matrix =         np.array([[ 1,  1,  1,  1, 10],
                    [ 1,  1,  1,  1, 11],
                    [ 1,  1,  1,  1, 12],
                    [ 1,  1,  1,  1, 13]])


##item a
def elim_gauss_sin_pivot(M): 
   for i in range(0, len(M[0]) - 2):
    for j in range(i+1, len(M)):
      if M[i][i] != 0:
        m_ji = M[j][i]/M[i][i]
        for k in range(i,len(M[0])):
          M[j][k] = M[j][k] - m_ji * M[i][k]
      else:
        for jerror in range(i+1, len(M)):
          if M[jerror][i] != 0:
            raise Exception("No se puede realizar la eliminacion gaussiana con i:" + str(i) + " y j: " + str(j))
   return M

def solve_sys_EGsin(M):
  M_res = elim_gauss_sin_pivot(M)
  b = []
  for i in range(0,len(M)):
    b.append(M[i][len(M[0])-1])
  return b


##item b 
b_matrix =         [[ 1,  1,  1,  1, 10],
                    [ 1,  1,  1,  1, 11],
                    [ 1,  2,  1,  1, 12],
                    [ 1,  2,  1,  1, 13]]

#print(solve_sys_EGsin(b_matrix))

#Punto 2

a = np.array([[ 1,  2],
              [3, 4]])


a_matrix2 = np.array([[ 1,  1,  0,  0, 0],
                     [ 2,  0,  0,  0, 0],
                     [ 0,  2,  1,  4, 0],
                     [ 0,  0,  2,  1, 0]])


##item a
def elim_gauss_con_pivot(M, threshold): 
   for i in range(0, len(M[0]) - 2):
    # print("i: " + str(i))  
    #Buscamos la fila de maximo valor para permutar
    j_max=i
    val_j_max=0
    for j_pivot in range(i+1, len(M)):
      if abs(M[j_pivot][i]) > val_j_max:
        val_j_max = abs(M[j_pivot][i])
        j_max = j_pivot
    # print(j_max)
    # print("M before:")
    # print(M)
    #Permutamos 
    for p in range(i, len(M[0])):
      m_ip = M[i][p]
      M[i][p] = M[j_max][p]
      M[j_max][p] = m_ip 

    # print("M after:")
    # print(M)
    #fila_pivot = M[j_max]
    #M[j_max] = M[i]
    #M[i] = fila_pivot
    #Hacemos el paso de eliminacion gaussiana 
    for j in range(i+1, len(M)):
      if M[i][i] != 0:  
        if(float(M[i][i]) <=threshold):
          print("Advertencia de error numerico, division por valor cercano a cero")
        m_ji = float(M[j][i])/float(M[i][i])
        # print("m_ji: " + str(m_ji) + " m_ji " + str(M[j][i]) + " m_ii: " + str(M[i][i]))
        for k in range(i,len(M[0])):
          M[j][k] = M[j][k] - m_ji * M[i][k]
      else:
        for jerror in range(i+1, len(M)):
          if M[jerror][i] != 0:
            raise Exception("No se puede realizar la eliminacion gaussiana con i:" + str(i) + " y j: " + str(j))
   return M

def solve_sys_EG(M):
  M_res = elim_gauss_con_pivot(M)
  b = []
  for i in range(0,len(M)):
    b.append(M[i][len(M[0])-1])
  return b

def print_matrix(M):
  for i in M:
    print(i)

# print(isinstance(elim_gauss_con_pivot(a_matrix2, 0.00011), np.ndarray) ) 

def coeficientes_elim_gauss_tridiaognal(M):
  coeficientes_computados = []
  for i in range(0, len(M))
    c_prima = 0
    if i == 0:
      c_prima = M[i][i + 1] /  M[i][i]
    else:
      c_prima = M[i][i + 1] /  M[i][i] - M[i][i - 1] * coeficientes_computados[i-1] #un coeficientes_computados.pop() tambien funcionaria

    coeficientes_computados.append(c_prima)
  return coeficientes_computados

def term_indep_elim_gauss_tridiagonal(M, coeficientes_computados):
terminos_indep_computados = []
  for i in range(0, len(M))
    d_prima = 0
    if i == 0:
      d_prima = M[i][i + 1] /  M[i][i]
    else:
      d_prima = (M[i][i + 1] + M[i][i - 1] * terminos_indep_computados[i - 1]) /  (M[i][i] - M[i][i - 1] * coeficientes_computados[i-1]) #un coeficientes_computados.pop() tambien funcionaria

    terminos_indep_computados.append(d_prima)
  return terminos_indep_computados  

def elim_gauss_tridiaognal(M):
  coeficientes = coeficientes_elim_gauss_tridiaognal(M)
  terminos_independientes = term_indep_elim_gauss_tridiagonal(M, coeficientes)

  ## falta reconstruir la solucion por back
