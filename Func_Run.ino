/*--------------------------------------------------------------------------------------------------------------------*
 | Ejecuta los pasos una y otra vez hasta que se pulse el botón "RESET"
 *--------------------------------------------------------------------------------------------------------------------*/
 
void Run()
{
  while (!bt.startsWith("RESET"))                           // MIENTRAS NO SE PRESIONE 'RESET' SE MANTIENE EN EL BUCLE
  {
    for (int i = 0; i < index; i++)                         // Recorro el arreglo hasta el valor del index que me indica cuantas posiciones se guardaron, para no recorrer todo el arreglo y no leer posiciones nulas o vacias.
    {
      if (Bluetooth.available())
      {
        bt = Bluetooth.readString();
        if (bt.startsWith("PAUSE"))                         // Si se preciona Pause, nos quedamos dentro de un bucle en el que solo responde al boton Reset y Run
        {
          while (!bt.startsWith("RUN"))                     // MIENTRAS NO SE PRESIONE 'RUN' SE MANTIENE EN EL BUCLE Y SOLO FUNCIONA BOTON "RESET"
          {
            if (Bluetooth.available())
            {
              bt = Bluetooth.readString();
              if (bt.startsWith("RESET"))                   // Si se presiona Reset cuando esta en pause se sale del bucle pause
                break;
            }
          }
        }
        if (bt.startsWith("ss")) speedRun = bt.substring(2, bt.length()).toInt();
        if (bt.startsWith("RESET")) break;                           // Nos salimos del modo Run al presionar Reset estando Pause, para no leer los movimientos guardados.
      }
      ReadMovementSave(baseArray, i, baseAct, base);                 // Funcion ReadMovementSave recibe 4 parametros (Array que guarda las posiciones, Indice 'i' del bucle for, Posicion Actual(Ant), Servo a mover)
      ReadMovementSave(shoulderArray, i, shoulderAct, shoulder);
      ReadMovementSave(elbowArray, i, elbowAct, elbow);
      ReadMovementSave(yawArray, i, yawAct, yaw);
      ReadMovementSave(wristArray, i, wristAct, wrist);
      ReadMovementSave(gripperArray, i, gripperAct, gripper);
    }
  }
}
