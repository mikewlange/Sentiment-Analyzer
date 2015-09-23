#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "RaspiCamCV.h"

int main() {
  RASPIVID_CONFIG* config = (RASPIVID_CONFIG*)malloc(sizeof(RASPIVID_CONFIG));
  config -> width = 320;
  config -> height = 240;
  config -> bitrate = 0;
  config -> framerate = 0;
  config -> monochrome = 1;

  RaspiCamCvCapture * camera = raspiCamCvCreateCameraCapture2(0, config);
  free(config);

  IplImage* image = raspiCamCvQueryFrame(camera);
  cvNamedWindow("Display", CV_WINDOW_AUTOSIZE);

  int pressedKey = 0;
  do {
    image = raspiCamCvQueryFrame(camera);
    cvShowImage("Display", image);
    pressedKey = cvWaitKey(1);
  } while (pressedKey != 27);

  return 0;
}
