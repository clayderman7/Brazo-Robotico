/*-------------------------------------------------------------------------------*
 | memset se utiliza para rellenar un bloque de memoria con un valor determinado |
 | memeset('Matriz','Dato a rellenar','Tamaño de la matriz')                     |
 *-------------------------------------------------------------------------------*/
 
void Reset()
{
  memset(baseArray, 0, sizeof(baseArray) / sizeof(baseArray[0]));                      // Rellena con el valor de "0" todas las posiciones de la matriz 
  memset(shoulderArray, 0, sizeof(shoulderArray) / sizeof(shoulderArray[0]));
  memset(elbowArray, 0, sizeof(elbowArray) / sizeof(elbowArray[0]));
  memset(yawArray, 0, sizeof(yawArray) / sizeof(yawArray[0]));
  memset(wristArray, 0, sizeof(wristArray) / sizeof(wristArray[0]));
  memset(gripperArray, 0, sizeof(gripperArray) / sizeof(gripperArray[0]));
  index = 0;
}
