/*test1.cpp
*创建时间：2015.10.13
*   作者：张京林
*/
#include <ros/ros.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <sensor_msgs/PointCloud2.h>
// #include <visualization_msgs/Marker.h>
#include <pcl_conversions/pcl_conversions.h> //包含pcl::PointCloud<pcl::PointXYZI>::const_iterator 等数据结构

#include <sstream>
#include <fstream>
#include <set>

int num = 0;

static void points_callback(const sensor_msgs::PointCloud2::ConstPtr& input)
{
    
    num++;
    pcl::PointCloud<pcl::PointXYZI> tmp;
    pcl::fromROSMsg(*input, tmp);
    //if(num ==1)
    //{
    //    pcl::io::savePCDFileASCII("data.pcd", *tmp);
    //}
    
    

}

//translate innovusion+imu data,send to autoware ndt 
int main(int argc, char **argv)
{

    ros::init(argc, argv, "preprocessing");
    ros::NodeHandle nh;
    ros::Subscriber points_sub = nh.subscribe("/iv_points2", 1, points_callback);
    // ros::Subscriber imu_sub = nh.subscribe("/imu/data", 1, imu_callback);

    ros::spin();

    return 0;
}

