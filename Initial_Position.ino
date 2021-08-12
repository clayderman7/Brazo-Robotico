void HomePosition()
{
    baseAct = 90;
    base.write(baseAct);
    delay(250);

    shoulderAct = 120;
    shoulder.write(shoulderAct);
    delay(250);

    elbowAct = 140;
    elbow.write(elbowAct);
    delay(250);

    yawAct = 90;
    yaw.write(yawAct);
    delay(250);

    wristAct = 90;
    wrist.write(wristAct);
    delay(250);

    gripperAct = 130;
    gripper.write(gripperAct);
    delay(250);
}
