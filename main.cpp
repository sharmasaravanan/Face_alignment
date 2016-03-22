///* 
// * File:   main.cpp
// * Author: HUBINO
// *
// * Created on 15 February, 2016, 5:23 PM
// */
//
//
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <dlib/opencv.h>

#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <dirent.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>

using namespace dlib;
using namespace std;
using namespace cv;
void listFile();

//int main()
//{
//    
//    listFile();
//    return 0;
//}
//
//void listFile()
//{
//        time_t start,end;
//        frontal_face_detector detector = get_frontal_face_detector();
//        shape_predictor sp;
//        deserialize("shape_predictor_68_face_landmarks.dat") >> sp;
//        time(&start);
//        
//        int counter=0;
//        string dirName="./final/";
//        DIR *pDIR;
//        cv::Mat frame;
//        struct dirent *entry;
//        string images;
//        string aux;
//        if( pDIR=opendir(dirName.c_str()))
//        {
//            while(entry = readdir(pDIR))
//            {
//                if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
//                {
//                    if( strstr(entry->d_name, ".jpg") )
//                    {
//                        cout << entry->d_name << "\n";
//                        images=entry->d_name;
//                        string aux;
//                        aux.append(dirName);
//                        aux.append(images);
//                        frame= imread(aux);
//                        string s=images+".jpg";
//                        //imshow(s,frame);
//                        array2d<rgb_pixel> image;
//                        assign_image(image,cv_image<rgb_pixel>(frame));
//                        
//                        std::vector<dlib::rectangle> dets = detector(image);
//                        std::vector<full_object_detection> shapes;
//                        for (unsigned long j = 0; j < dets.size(); ++j)
//                            {
//                               full_object_detection shape = sp(image, dets[j]);
//                               shapes.push_back(shape);
//
//                               for(int i=1;i<=16;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=28;i<=30;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=18;i<=21;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=23;i<=26;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=31;i<=35;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=37;i<=41;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=43;i<=47;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=49;i<=59;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//                               for(int i=61;i<=67;++i)
//                               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//            
//             
//                               cv::line(frame,Point(shape.part(30).x(),shape.part(30).y()),Point(shape.part(35).x(),shape.part(35).y()),Scalar(0,255,0),2); 
//                               cv::line(frame,Point(shape.part(60).x(),shape.part(60).y()),Point(shape.part(67).x(),shape.part(67).y()),Scalar(0,255,0),2);
//                               cv::line(frame,Point(shape.part(48).x(),shape.part(48).y()),Point(shape.part(59).x(),shape.part(59).y()),Scalar(0,255,0),2);
//                               cv::line(frame,Point(shape.part(42).x(),shape.part(42).y()),Point(shape.part(47).x(),shape.part(47).y()),Scalar(0,255,0),2);
//                               cv::line(frame,Point(shape.part(36).x(),shape.part(36).y()),Point(shape.part(41).x(),shape.part(41).y()),Scalar(0,255,0),2);
//                     
//                            }
//            
//                        //Dlib Face-Alignment Image Properties Set
//                        dlib::array<array2d<rgb_pixel> > face_chips;
//                        extract_image_chips(image, get_face_chip_details(shapes), face_chips);
//                        //win.set_image(tile_images(face_chips));
//                        //Pushing the Array Element to vector
//            
//                        cv::Mat cvimg;
//                        for(int i=0;i<face_chips.size();++i)
//                            {
//                               cvimg= dlib::toMat(face_chips[i]);
//                               //cv::imshow("Aligned Face:",cvimg);
//                               cv::resize(cvimg,cvimg,Size(96,96),0,0,INTER_LINEAR);
//                               cv::imwrite(s,cvimg);
//                               face_chips.clear();
//                               //cv::waitKey(0);
//                            }
//                        time(&end);                           
//                    }
//                            
//                else
//                    {
//                        cout <<"no image file"<<endl;
//                    }
//                            
//                }
//            }
//        }
//}
// ----------------------------------------------------------------------------------------
std::vector<std::string> listpath;
void recursive_listing(char *ptr)
{

        DIR *dp;
        dirent *d;

	if((dp = opendir(ptr)) == NULL)
		perror("opendir");

	while((d = readdir(dp)) != NULL)
	{
            
		if(!strcmp(d->d_name,".") || !strcmp(d->d_name,".."))
                {
			continue;
                }
                 string dirpath=string(ptr)+"/"+d->d_name;
		struct stat sb;

if (stat(dirpath.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode))
{
//			cout << d->d_name << ":" << endl;
//                        string dirpath=string(ptr)+"/"+d->d_name;
                       // cout<<"dirpath :"<<dirpath<<endl;
			recursive_listing(dirpath.c_str());	
		}
		else
                {
                     string dirpath1=string(ptr)+"/"+d->d_name;
                     listpath.push_back(dirpath1);
                    // cout << "File :"<< dirpath1 << endl;
                }
                
	}
	return;
}
int main(int argc, char** argv) 
{  
    
        //time_t start,end;
        frontal_face_detector detector = get_frontal_face_detector();
       
        //time(&start);
        //int counter=0;
        
         
        //image_window win;
           
           
           for(;;) 
           {
              recursive_listing(argv[1]);
              cout<<"total file siz"<<listpath.size()<<endl;
              for(int i=0;i<listpath.size();i++)
             {
              cv::Mat frame=imread(listpath[i]);
//              cv::Mat frame1=imread(listpath[i]);
              cout << "File :"<< listpath[i] << endl;
               cv::resize(frame,frame,cv::Size(250,250));
                      
                if( frame.empty() )
                {
                printf("\nCan not find image file\n");
                return -1;
                }
                       
            array2d<rgb_pixel> image;
            assign_image(image,cv_image<rgb_pixel>(frame));
            std::vector<dlib::rectangle> dets = detector(image);
            shape_predictor sp;
            deserialize("shape_predictor_68_face_landmarks.dat") >> sp;
            std::vector<full_object_detection> shapes;
            for (unsigned long j = 0; j < dets.size(); ++j)
            {
               full_object_detection shape = sp(image, dets[j]);
               shapes.push_back(shape);
      
               for(int i=1;i<=16;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=28;i<=30;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=18;i<=21;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=23;i<=26;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=31;i<=35;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=37;i<=41;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=43;i<=47;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=49;i<=59;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
               for(int i=61;i<=67;++i)
               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
            
             
            cv::line(frame,Point(shape.part(30).x(),shape.part(30).y()),Point(shape.part(35).x(),shape.part(35).y()),Scalar(0,255,0),2); 
            cv::line(frame,Point(shape.part(60).x(),shape.part(60).y()),Point(shape.part(67).x(),shape.part(67).y()),Scalar(0,255,0),2);
            cv::line(frame,Point(shape.part(48).x(),shape.part(48).y()),Point(shape.part(59).x(),shape.part(59).y()),Scalar(0,255,0),2);
            cv::line(frame,Point(shape.part(42).x(),shape.part(42).y()),Point(shape.part(47).x(),shape.part(47).y()),Scalar(0,255,0),2);
            cv::line(frame,Point(shape.part(36).x(),shape.part(36).y()),Point(shape.part(41).x(),shape.part(41).y()),Scalar(0,255,0),2);
            
            
           
            }
            
            //Dlib Face-Alignment Image Properties Set
            dlib::array<array2d<rgb_pixel> > face_chips;
            extract_image_chips(image, get_face_chip_details(shapes), face_chips);
            //win.set_image(tile_images(face_chips));
            
           //Pushing the Array Element to vector
            
           cv::Mat cvimg;
           
           if(face_chips.size()==1)
           {
           for(int j=0;j<face_chips.size();++j)
            {
              
               cvimg= dlib::toMat(face_chips[j]);
               
               cv::imshow("Aligned Face:",cvimg);
               cv::resize(cvimg,cvimg,Size(96,96),0,0,INTER_LINEAR);
               cout<<"location:"<<listpath[i]<<endl;
              cv::imwrite(listpath[i].c_str(),cvimg);
               // cv::imwrite("Aligned Face.jpg",cvimg);
               face_chips.clear();
            
//               
//              // cv::waitKey(10);
               break;
            }
           }
           else
           {
               if( remove( listpath[i].c_str()) != 0 )
              perror( "Error deleting file" );
              else
              puts( "File successfully deleted" );
           }
            //time(&end);
            cv::imshow("Landmarks Face",frame);
            //cv::imwrite("landmark.jpg",frame);
            cv::waitKey(30);
           // continue;
           }
           }      
        
} 
//--------------------------------------------------------------------------------------

//int main(int argc, char** argv) 
//{  
//    
//        time_t start,end;
//        frontal_face_detector detector = get_frontal_face_detector();
//        shape_predictor sp;
//        deserialize("shape_predictor_68_face_landmarks.dat") >> sp;
//        time(&start);
//        int counter=0;
//        VideoCapture cap(0);
//         if( !cap.isOpened() )
//            {
//                printf("\nCan not open camera or video file\n");
//                return -1;
//             }
//        //image_window win;
//        for (;;)
//        {
//           
//            Mat frame;
//            cap>>frame;
//           
//            
//            array2d<rgb_pixel> image;
//            assign_image(image,cv_image<rgb_pixel>(frame));
//            std::vector<dlib::rectangle> dets = detector(image);
//         
//            std::vector<full_object_detection> shapes;
//            for (unsigned long j = 0; j < dets.size(); ++j)
//            {
//               full_object_detection shape = sp(image, dets[j]);
//               shapes.push_back(shape);
//      
//               for(int i=1;i<=16;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=28;i<=30;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=18;i<=21;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=23;i<=26;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=31;i<=35;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=37;i<=41;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=43;i<=47;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=49;i<=59;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//               for(int i=61;i<=67;++i)
//               cv::line(frame,Point(shape.part(i).x(),shape.part(i).y()),Point(shape.part(i-1).x(),shape.part(i-1).y()),Scalar(0,255,0),2);
//            
//             
//            cv::line(frame,Point(shape.part(30).x(),shape.part(30).y()),Point(shape.part(35).x(),shape.part(35).y()),Scalar(0,255,0),2); 
//            cv::line(frame,Point(shape.part(60).x(),shape.part(60).y()),Point(shape.part(67).x(),shape.part(67).y()),Scalar(0,255,0),2);
//            cv::line(frame,Point(shape.part(48).x(),shape.part(48).y()),Point(shape.part(59).x(),shape.part(59).y()),Scalar(0,255,0),2);
//            cv::line(frame,Point(shape.part(42).x(),shape.part(42).y()),Point(shape.part(47).x(),shape.part(47).y()),Scalar(0,255,0),2);
//            cv::line(frame,Point(shape.part(36).x(),shape.part(36).y()),Point(shape.part(41).x(),shape.part(41).y()),Scalar(0,255,0),2);
//            
//            
//           
//            }
//            
//            //Dlib Face-Alignment Image Properties Set
//            dlib::array<array2d<rgb_pixel> > face_chips;
//            extract_image_chips(image, get_face_chip_details(shapes), face_chips);
//                //win.set_image(tile_images(face_chips));
//            
//           
//            //Pushing the Array Element to vector
//            
//           cv::Mat cvimg;
//           for(int i=0;i<face_chips.size();++i)
//            {
//               cvimg= dlib::toMat(face_chips[i]);
//               
//               cv::imshow("Aligned Face:",cvimg);
//               face_chips.clear();
//               if (cv::waitKey(10)>=0)
//           break;
//            }
//
//            time(&end);
//               ++counter;
//               double sec=difftime(end,start);
//               double fps=counter/sec;
//              
//               char fpsC[255];
//	       sprintf(fpsC, "%d", (int)fps);
//	       string fpsSt("FPS:");
//	       fpsSt += fpsC;
//	       cv::putText(frame, fpsSt, cv::Point(10,20), CV_FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255,0,0));
//            
//            cv::imshow("Landmarks Face",frame);
//            if (cv::waitKey(10)>=0)
//           break;
//        }
//    
//}
