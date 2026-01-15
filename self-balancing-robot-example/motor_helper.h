#define MOTORA 0
#define MOTORB 1
#define enA 9
#define enB 10
#define in1 5
#define in2 6
#define in3 7
#define in4 8
#define FORWARD 0
#define BACK 1

static int motor_a_direction;
static int motor_b_direction;

static int motor_a_speed;
static int motor_b_speed;

void initializeMotors();

// void invertMotorDirection(int motor);

void setMotorDirection(int motor, int direction);