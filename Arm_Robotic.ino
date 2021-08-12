#include <Servo.h>
#include <SoftwareSerial.h>

/*----------------------- Objeto SoftwareSerial ----------------------*/
SoftwareSerial Bluetooth(3, 4); // RX, TX

/*----------------------- Objetos Servos -----------------------------*/
Servo base;
Servo shoulder;             // Hombro
Servo elbow;                // Codo
Servo yaw;                  // Muñeca rotacion horizontal
Servo wrist;                // Muñeca vertical
Servo gripper;              // Pinza

/*----------------------- Pines servos ------------------------------*/
const int pinBase = 5;
const int pinShoulder = 11;
const int pinElbow = 7;
const int pinYaw = 8;
const int pinWrist = 9;
const int pinGripper = 10;

/*----------------------- Variables de velocidades(Speed) - Mientras mas alto el valor mas lento ------------------------*/
int speedBase = 30;
int speedShoulder = 30;
int speedElbow = 30;
int speedYaw = 28;
int speedWrist = 28;
int speedGripper = 20;
int speedRun = 30;

/*----------------------- Posiciones: Nueva - Actual -----------------------------------*/
int baseNewPos, shoulderNewPos, elbowNewPos, yawNewPos, wristNewPos, gripperNewPos;
int baseAct, shoulderAct, elbowAct, yawAct, wristAct, gripperAct;

/*----------------------- Arreglos para almacenar las posiciones --------------------------*/
int baseArray[50], shoulderArray[50], elbowArray[50], yawArray[50], wristArray[50], gripperArray[50];
int index = 0;

/*----------------------- Para almacenar la cadena que llega por bluetooth ------------------*/
String bt;


void setup()
{
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(10);

  base.attach(pinBase, 550, 2400);                 // ancho min y max MG996R ó MG995 base
  shoulder.attach(pinShoulder, 650, 1400);         // ancho min y max MG946R ó MG995 shoulder
  elbow.attach(pinElbow, 650, 1400);               // ancho min y max MG946R ó MG995 elbow
  yaw.attach(pinYaw, 550, 2350);                   // ancho min y max MG90s  ó SG90  yaw
  wrist.attach(pinWrist, 800, 1290);               // ancho min y max MG90s  ó SG90  muneca
  gripper.attach(pinGripper, 700, 1290);           // ancho min y max MG90s  ó SG90  gripper

  HomePosition();                                  // Posiciones iniciales
}


void loop()
{
  if (Bluetooth.available())
  {
    bt = Bluetooth.readString();                                 // Leemos cadena que llegó y la guardamos en lavariable bt
    if (bt.startsWith("s1"))
    {
      baseNewPos = bt.substring(2, bt.length()).toInt();         // Extraigo los caracteres desde la poisicion 2 en adelante Ejemplo: "s1120" a "120" y convierto de string a entero
      MovingPosition(baseNewPos, baseAct, speedBase, base);      // Funcion MovingPosition recibe 4 parametros, ( Nueva posicion, Posicion actual, Velocidad movimiento(delay), Servo a mover)
      baseAct = baseNewPos;                                      // El angulo movido(baseNewPos) se convierte en la posicion actual (baseAct)
    }
    else if (bt.startsWith("s2"))
    {
      shoulderNewPos = bt.substring(2, bt.length()).toInt();
      MovingPosition(shoulderNewPos, shoulderAct, speedShoulder, shoulder);
      shoulderAct = shoulderNewPos;
    }
    else if (bt.startsWith("s4"))
    {
      elbowNewPos = bt.substring(2, bt.length()).toInt();
      MovingPosition(elbowNewPos, elbowAct, speedElbow, elbow);
      elbowAct = elbowNewPos;
    }
    else if (bt.startsWith("s5"))
    {
      yawNewPos = bt.substring(2, bt.length()).toInt();
      MovingPosition(yawNewPos, yawAct, speedYaw, yaw);
      yawAct = yawNewPos;
    }
    else if (bt.startsWith("s6"))
    {
      wristNewPos = bt.substring(2, bt.length()).toInt();
      MovingPosition(wristNewPos, wristAct, speedWrist, wrist);
      wristAct = wristNewPos;
    }
    else if (bt.startsWith("s7"))
    {
      gripperNewPos = bt.substring(2, bt.length()).toInt();
      MovingPosition(gripperNewPos, gripperAct, speedGripper, gripper);
      gripperAct = gripperNewPos;
    }
    else if (bt.startsWith("SAVE"))
      Save();
    else if (bt.startsWith("RUN"))
      Run();
    else if (bt.startsWith("RESET"))
    {
      Reset();
      HomePosition();                                            // Volvemos a la posicion inicial al presionar Reset en el modo manual.
    }
  }
}
