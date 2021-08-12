inline void MovingPosition (int &newPosition, int &currentPosition, int &Speed, Servo &servo)
{
  if (currentPosition == newPosition) {}
  else if (currentPosition > newPosition)
  {
    for (int j = currentPosition; j >= newPosition; j--) {
      servo.write(j);
      delay(Speed);
    }
  }
  else
  {
    for (int j = currentPosition; j <= newPosition; j++) {
      servo.write(j);
      delay(Speed);
    }
  }
}


inline void ReadMovementSave(int Array[], int &I, int &currentPosition, Servo &servo)
{
  if (currentPosition == Array[I]) {}
  else if (currentPosition > Array[I])
  {
    for (int j = currentPosition; j > Array[I]; j--) {
      servo.write(j);
      delay(speedRun);
    }
    currentPosition = Array[I];
  }
  else
  {
    for (int j = currentPosition; j < Array[I]; j++) {
      servo.write(j);
      delay(speedRun);
    }
    currentPosition = Array[I];
  }
}
