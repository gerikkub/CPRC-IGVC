/*
 * test.cpp
 *
 *  Created on: 09-08-2010
 *  Author: Konrad Banachowicz
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

#include "LMS1xx.h"
#include <iostream>
#include <string.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <boost/thread/thread.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace pcl;
int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

	LMS1xx laser;
	scanData data;

	laser.connect("192.168.1.5");
	if(!laser.isConnected())
	{
		std::cout << "connection failend" << std::endl;
		return 0;
	}

	std::cout << "Connected to laser" << std::endl;

	std::cout << "Loging in ..." << std::endl;
    laser.login();

	laser.stopMeas();

	std::cout << "Geting scan configuration ..." << ::std::endl;
	scanCfg c = laser.getScanCfg();

	//std::cout << "Scanning Frequency : " << c.scaningFrequency/100.0 << "Hz AngleResolution : " << c.angleResolution/10000.0 << "deg " << std::endl;

	c.angleResolution = 5000;
	c.scaningFrequency = 5000;

	laser.setScanCfg(c);

	scanDataCfg cc;
	cc.deviceName = false;
	cc.encoder = 0;
	cc.outputChannel = 3;
	cc.remission = true;
	cc.resolution = 0;
	cc.position = false;
	cc.outputInterval = 1;

	laser.setScanDataCfg(cc);

	int ret = 0;
	std::cout << "Start measurements ..." << std::endl;
	laser.startMeas();

	std::cout << "Wait for ready status ..." << std::endl;
	ret = 0;
	while (ret != 7)
	{
		ret = laser.queryStatus();
		std::cout << "status : " << ret << std::endl;
        sleep(1);
    }

	std::cout << "Laser ready" << std::endl;

	std::cout << "Start continuous data transmission ..." << std::endl;
    laser.scanContinous(1);

    while(1)
    {

		std::cout << "Receive data sample ..." << std::endl;
		laser.getData(data);

        for(int i = i;  i < data.dist_len1; i++)
            {
            double y = data.dist1[i]*sin(((i/data.dist_len1)*270)*3.14);
            double x = data.dist1[i]*cos(((i/data.dist_len1)*270)*3.14);

            PointXYZ point( x,y ,0 );

            cloud->push_back(point );
            }
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyzrgbb (new pcl::PointCloud<pcl::PointXYZRGB>);


        for (size_t i = 0; i < cloud_xyzrgbb->points.size (); ++i)
       {
       cloud_xyzrgbb->points[i].g = 255;

       }

         //pcl::visualization::CloudViewer viewer ("Result viewer");
         //viewer.showCloud(cloud_output);
         boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
         viewer->setBackgroundColor (0, 0, 0);
         pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud_xyzrgb);
         viewer->addPointCloud<pcl::PointXYZRGB> (cloud_xyzrgb, rgb, "sample cloud");
       /*
         pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgbb(cloud_xyzrgbb);
         viewer->addPointCloud<pcl::PointXYZRGB> (cloud_xyzrgbb, rgbb, "sample cloudb");

       */
         viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");

        viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloudb");

        viewer->addCoordinateSystem 	( 	1,0,0,100);

         viewer->initCameraParameters ();


           viewer->spin();

       while (!viewer->wasStopped ())
         {
         double x , y , z , r , b,o;
         cout << "give x y  z \n";
         cin >> x ;
         cin >> y;
         cin >> z;

        viewer->setCameraPosition 	( 	x,y,z,0,0,0,0);
        //updateCamera ();

         }


      //  sleep(1);

        std::cout << "time";
           //for(int i =0; i <  100; i++ )
            //   std::cout  << "value"<< i << " "<< data.dist1[i] << "\n";
          // for(int i =0 ; i < 1000000; i++);


	}

	std::cout << "Stop continuous data transmission ..." << std::endl;
	laser.scanContinous(0);

	laser.stopMeas();

	std::cout << "Disconnect from laser" << std::endl;
	laser.disconnect();

	return 0;
}



