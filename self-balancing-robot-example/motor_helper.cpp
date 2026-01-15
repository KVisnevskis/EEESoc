#include "motor_helper.h"

void initializeMotors()
{
    motor_a_direction = FORWARD;
    motor_b_direction = FORWARD;
    motor_a_speed = 0;
    motor_b_speed = 0;
}

void setMotorDirection(int motor, int direction)
{
    if ((direction != FORWARD) || direction != BACK )
        return;

    if (motor == MOTORA)
        motor_a_direction = direction;
    else if (motor == MOTORB)
        motor_b_direction = direction;
    else 
        return;
}

void setMotorSpeed(int motor, int speed)
{
    if (speed > 255)
        speed = 255;

    if (speed < 0)
        speed = 0;

    if (motor == MOTORA)
        motor_a_speed = speed;
    else if (motor == MOTORB)
        motor_b_speed = speed;
    else 
        return;
}