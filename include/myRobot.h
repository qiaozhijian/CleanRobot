//
// Created by qzj on 2020/7/3.
//

#ifndef SRC_MYROBOT_H
#define SRC_MYROBOT_H

#include <Eigen/Core>
#include <Eigen/Geometry>

class MyRobot{
public:
    int cnt=0;
    uint32_t chassisTime = 0; //移动底盘的时间

    bool isAllOn = false;
    bool allSensorEnable = false;
    bool sendRegular = false;
    uint8_t moving = 0;

    double tof = 0;// 离墙距离 m
    uint16_t leftCur = 0; //左轮电流
    uint16_t rightCur = 0; //右轮电流
    char leftCharge = 0; //左接收
    char midLeftCharge = 0; //中左接收
    char midRightCharge = 0; //中右接收
    char rightFwdCharge = 0; //右前接收
    char rightCharge = 0; //右接收
    double accel_x = 0.0;
    double accel_y = 0.0;
    double accel_z = 0.0;
    double gyro_x = 0.0; //弧度制
    double gyro_y = 0.0; //弧度制
    double gyro_z = 0.0; //弧度制
    double pitch = 0.0;
    double roll = 0.0;
    double yaw = 0.0;
    int16_t pulseLeft = 0;//左轮脉冲
    int16_t pulseRight = 0;//右轮脉冲
    double odometer_x = 0.0;
    double odometer_y = 0.0;
    double odometer_theta = 0.0; //弧度制

    string topic_imu,topic_camera0,topic_camera1;
    double img0Time,img1Time,imuTime,timeInit;

    // Location of the ROS bag we want to read in
    std::string path_to_bag;
    // Get our start location and how much of the bag we want to play
    // Make the bag duration < 0 to just process to the end of the bag
    double bag_start, bag_durr;
    // We should load the bag as a view
    // Here we go from beginning of the bag to the end of the bag
    rosbag::View view, view_full;
    // Load rosbag here, and find messages we can play
    rosbag::Bag bag;

    cv::Mat img0;
    cv::Mat img1;

    void HandleRosbag(rosbag::MessageInstance m);
    int RosbagInit();
    MyRobot(void);

    ofstream odometryFile;

private:
    int a,b,c;

};

#endif //SRC_MYROBOT_H
