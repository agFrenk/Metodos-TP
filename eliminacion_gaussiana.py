a_matrix =         [[ 1,  1,  1,  1, 10],
                    [ 1,  1,  1,  1, 11],
                    [ 1,  1,  1,  1, 12],
                    [ 1,  1,  1,  1, 13]]


print(len(a_matrix[0]))

def elim_gauss_sin_pivot(M):
   for i in range(0, len(M[0]) - 2):
    print(i)
    for j in range(i+1, len(M)):
      print( "i = " + str(i) + " M[i][i] = " + str(M[i][i]))
      if M[i][i] != 0:
        m_ji = M[j][i]/M[i][i]
        for k in range(i,len(M[0])):
          M[j][k] = M[j][k] - m_ji * M[i][k]
      else:
        for jerror in range(i+1, len(M)):
          if M[jerror][i] != 0:
            print("Error")
            return 0  ## levantar error
   print(M)
   return M

elim_gauss_sin_pivot(a_matrix)
