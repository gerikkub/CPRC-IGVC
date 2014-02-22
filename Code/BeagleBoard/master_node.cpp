#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/NavSatFix.h"
#include "beagle_pkg/ArdMsg.h"

sensor_msgs::LaserScan scan_data;
sensor_msgs::NavSatFix gps_data;
beagle_pkg::ArdMsg ard_data;

void laser_scanner_callback(const sensor_msgs::LaserScan::ConstPtr& scan) {
//set data to global data
}

void gps_callback(const sensor_msgs::NavSatFix::ConstPtr& scan) {
//set data to global data
}

void ard_callback(const beagle_pkg::ArdMsg::ConstPtr& msg) {
//set data to global data
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

   ros::init(argc, argv, "BeagleMaster");
   ros::NodeHandle n;

   /* Make BeagleMaster a publisher of the motor controller ros msg.
   * Ros provides this to us via through the Twist message, which includes
   * two vectors: one corresponding to linear velocity (linear), and 
   * one corresponding to angular velocity (angular)
   */
   ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("vel", 1000);

   /* Make BeagleMaster a subscriber to lidar topic. This is provided by
   * Ros's LaserScan message.
   */
   ros::Subscriber laser_sub = n.subscribe<sensor_msgs::LaserScan>("scan", 10, laser_scanner_callback);

   /* Make BeagleMaster a subscriber to gps topic. This is provided by
   * Ros's NavSatFix message.
   */
   ros::Subscriber gps_sub = n.subscribe<sensor_msgs::NavSatFix>("gps", 10, gps_callback);

   /* Make BeagleMaster a subscriber to arduino topic. */
   ros::Subscriber ard_sub = n.subscribe<beagle_pkg::ArdMsg>("ardData", 10, ard_callback);

   ros::Rate loop_rate(10);

   /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
   int count = 0;
   while (ros::ok())
   {
      //Check for updates to msg files.
      ros::spinOnce();
    

      processData();


      loop_rate.sleep();
      ++count;
   }

   return 0;
}

/* processData is the main decision function that
 * will publish commands to the motor controller
 * node and possibly ask for arduino data.
 */
void processData() {

   geometry_msgs::Twist command;
   
   /* TODO: look at global data (scan_data, gps_data, ard_data)
    * and make decision of what to send to the motor node.
    */
   vel_pub.publish(command);
}
