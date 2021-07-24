#include "qingzhou_bringup.h"

void actuator::process_imu()
{
	sensor_msgs::Imu imuMsg;
	sensor_msgs::MagneticField magMsg;

	ros::Time current_time = ros::Time::now();

	imuMsg.header.stamp = current_time;
	imuMsg.header.frame_id = "imu_link";
	imuMsg.angular_velocity.x = gyroX;
	imuMsg.angular_velocity.y = gyroY;
	imuMsg.angular_velocity.z = gyroZ;
	imuMsg.angular_velocity_covariance = {
		0.04, 0.0, 0.0,
		0.0, 0.04, 0.0,
		0.0, 0.0, 0.04};

	imuMsg.linear_acceleration.x = accelX;
	imuMsg.linear_acceleration.y = accelY;
	imuMsg.linear_acceleration.z = accelZ;
	imuMsg.linear_acceleration_covariance = {
		0.04, 0.0, 0.0,
		0.0, 0.04, 0.0,
		0.0, 0.0, 0.04};
	pub_imu.publish(imuMsg); //发布imuMsg

	magMsg.header.stamp = current_time;
	magMsg.header.frame_id = "base_link";
	magMsg.magnetic_field.x = magX;
	magMsg.magnetic_field.y = magY;
	magMsg.magnetic_field.z = magZ;
	magMsg.magnetic_field_covariance = {
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 0.0};
	pub_mag.publish(magMsg); //发布magMsg
}
