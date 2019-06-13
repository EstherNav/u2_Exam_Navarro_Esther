     /*
          File: u2_Exam_Navarro_Esther.c
  
    */

#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>
#include <webots/distance_sensor.h>
#include <webots/position_sensor.h>

#include <stdio.h>
/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*keyboard devices*/
  wb_keyboard_enable(TIME_STEP);
  int pressed_key;

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   /*Motor devices*/
   WbDeviceTag wheel_right= wb_robot_get_device("motor_right");
   WbDeviceTag wheel_left= wb_robot_get_device("motor_left");
   /*distance sensor devices*/
   WbDeviceTag dist_sensor=wb_robot_get_device("distance_sensor");

   wb_motor_set_position(wheel_right, INFINITY);
   wb_motor_set_position(wheel_left, INFINITY);
   
   
   /*declarate variables*/
   
   double RPM1_value;
   double V1_value;
   double RPM2_value;
   double v2_value;
  
   
   wb_distance_sensor_enable(dist_sensor, TIME_STEP);
   double ds_value;

   /*encoder*/
   WbDeviceTag encoder = wb_robot_get_device("encoder1");
   wb_position_sensor_enable(encoder, TIME_STEP);
   double ps_value;
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  
  while (wb_robot_step(TIME_STEP) != -1) {

    /* Read the sensors : */

    /*Keyboard sensor*/
    pressed_key = wb_keyboard_get_key();

   /*Read distance sensor*/
    ds_value = wb_distance_sensor_get_value(dist_sensor);
    printf("Distance sensor: %lf\n", ds_value);

    /*Read encoder1*/
    ps_value = wb_position_sensor_get_value(encoder);
    printf("encoder = %lf\n", ps_value);
    double rpm_value;

   

    /*Keyboard conditions*/

    if (pressed_key == WB_KEYBOARD_UP){
     /*1rad/s=1m/s*/
     V1_value=-3; 
     V2_value=-3; 
     
     /*RPM= v/(radio(0.10472))*/
     RMP1_value=-60.8234; 
     RPM2_value=-60.8234; 
     wb_motor_set_velocity(wheel_right, -40);
     wb_motor_set_velocity(wheel_left,  -40);
     
     
     printf("Velocity right wheel  %lf m/s\n", V1_value );
     printf("Velocity left wheel  %lf m/s\n", V2_value );
     printf("RPM left wheel  %lf \n", RPM1_value );
     printf("RPM right wheel  %lf \n", RPM2_value );
     } 
     
    if (pressed_key==WB_KEYBOARD_DOWN){
     wb_motor_set_velocity(wheel_right, 0.1);
     wb_motor_set_velocity(wheel_left,  0.1);
     
     /*1rad/s=1m/s*/
     vl_value=0.1; 
     vr_value=0.1; 
     
     /*RPM= v/(radio(0.10472))*/
     rpml_value=2.0274; 
     rpmr_value=2.0274; 
     
     printf("Velocity right wheel   %lf m/s\n", vr_value );
     printf("Velocity left wheel  %lf m/s\n", vl_value );
     printf("RPM left wheel  %lf \n", rpml_value );
     printf("RPM right wheel  %lf \n", rpmr_value );
     }
    if (pressed_key==WB_KEYBOARD_RIGHT){
     wb_motor_set_velocity(wheel_left,   40);
     wb_motor_set_velocity(wheel_right, -40);
     
     /*1rad/s=1m/s*/
     V1_value=40; 
     V2_value=-40; 
     
     /*RPM= v/(radio(0.10472))*/
     RPM1_value=101.3723; 
     RPM2_value=-101.3723; 
     
     printf("Velocity right wheel   %lf m/s\n", V2_value );
     printf("Velocity left wheel  %lf m/s\n", V1_value );
     printf("RPM left wheel  %lf \n", RPM1_value );
     printf("RPM right wheel  %lf \n", RPM2_value );
     }
     
     
    if (pressed_key==WB_KEYBOARD_LEFT){
     wb_motor_set_velocity(wheel_left,  -40);
     wb_motor_set_velocity(wheel_right,  40);
    
    /*1rad/s=1m/s*/
     V1_value=-5; 
     V2_value=5; 
     /*RPM= v/(radio(0.10472))*/
     rpml_value=-101.3723; 
     rpmr_value=+101.3723; 
     
     printf("Velocity right wheel   %lf m/s\n", V2_value );
     printf("Velocity left wheel  %lf m/s\n", V1_value );
     printf("RPM left wheel  %lf \n", RPM1_value );
     printf("RPM right wheel  %lf \n", RPM2_value );
     }



  };


  wb_robot_cleanup();

  return 0;
}

