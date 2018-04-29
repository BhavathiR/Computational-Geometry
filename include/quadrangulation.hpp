#include <iostream>
#include <algorithm>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <opencv2/opencv.hpp>

#include "Quadrangulate.h"
#include "Quadrilateral.h"

void start_Quadrangulation()
{
	cv::RNG rng;
    InputInfo info;
    info.canvas = cv::Mat(WIN_HEIGHT, WIN_WIDTH, CV_8UC3);

    cout<<"\n\nRunning Polygon Quadrangulation:"<<endl;
    cout<<"Use Delone? (y/n):";
    char c;
    cin>>c;
    bool ch=c==('y'||c=='Y');

    // for(int i=0;i<n;++i)
    //     info.points.push_back(Point((rand()%51200)/100,(rand()%51200)/100));

    imshow("Result", info.canvas);
    cv::setMouseCallback("Result", mouse_handler, &info);

    while (control)
    {
        cv::waitKey(10);
    }

    vector<Quadrilateral> q_list;
    Quadrangulate q;

    cout<<"\nNumber of points: "<<info.points.size()<<endl<<endl;
    clock_t t=clock();
    q.Quadrangulation(info.points,q_list, ch);
    t=clock()-t;
    for (auto t : q_list)
    {
        cv::Point v4[1][4];
        v4[0][0] = cv::Point(t.point1.x, t.point1.y);
        v4[0][1] = cv::Point(t.point2.x, t.point2.y);
        v4[0][2] = cv::Point(t.point3.x, t.point3.y);
        v4[0][3] = cv::Point(t.point4.x, t.point4.y);
        const cv::Point* ppt[1] = { v4[0] };
        int npt[] = { 4 };

        cv::fillPoly(info.canvas, ppt, npt, 1, cv::Scalar(rng.next() % 200 + 55, rng.next() % 200 + 55, rng.next() % 200 + 55,rng.next() % 200 + 55), 8);
    }

    cout << "\nTime taken by Algorithm:" << t * 1000.0 / CLOCKS_PER_SEC << " ms"<<endl;

    // Visualization
    for (auto point : info.points)
    {
        circle(info.canvas, cv::Point2i(point.x, point.y), 1, cv::Scalar(200,100,200), 2);
    }
    stringstream ss;
    ss<<"../images/quadrangulation"<<info.points.size()<<"_"<<fixed<<setprecision(3)<<t<<".jpeg";
    string fname;
    ss>>fname;
    imwrite(fname, info.canvas);
    imshow("Result", info.canvas);

    cv::waitKey();
    
}