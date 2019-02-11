#include <QCoreApplication>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    VideoCapture camera(0);
    Mat gray;
    Mat gray2;
    Mat frame;

    Ptr<ORB> orb = ORB::create(500);
    Ptr<DescriptorMatcher>matcher=DescriptorMatcher::create("BruteForce-Hamming");
    vector<KeyPoint> keypts1, keypts2;
    vector<DMatch> matches;
    Mat imageMatch;
    Mat desc1, desc2;

    while (1) {
        camera >> frame;
        cvtColor(frame, gray, CV_BGR2GRAY);
        cvtColor(frame, gray2, CV_BGR2GRAY);
        orb->detectAndCompute(gray, noArray(), keypts1, desc1);
        orb->detectAndCompute(gray2, noArray(), keypts2, desc2);
        matcher->match(desc1,desc2,matches);
        drawMatches(gray,keypts1,gray2,keypts2,matches,imageMatch);
//        imshow("gray1",gray);
//        imshow("gray2",gray2);
        imshow("imageMatch",imageMatch);
        if ( waitKey(1) == 27)break;
    }
}
