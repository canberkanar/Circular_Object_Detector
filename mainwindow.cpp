#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QtCore>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  capWebcam.open(0);//Opens the first Webcam available on the device

  if(capWebcam.isOpened() == false){//Checks if Webcam access succeeds
    ui->txtXYRadius->appendPlainText("Error, Webcam can't be accessed successfully!");
  return;

    }

  tmrTimer = new QTimer();
  connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameandUpdateGUI()));//Connects timer's timeout signal to the slot:processFrameandUpdateGUI
  tmrTimer->start(20);//Emits signal at every 20 miliseconds
  manageTimer=0;
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::processFrameandUpdateGUI(){//Updates the displayed Images
  capWebcam.read(matOriginal);

  if(matOriginal.empty() == true)
    return;

  cv::cvtColor(matOriginal, matOriginal, CV_BGR2HSV);//Manages the color standarts of the captured image


////////////////////////////////Colors to be detected////////////////////////////////////////BGR(Blue, Green, Red)

  //cv::inRange(matOriginal, cv::Scalar(0, 0, 175), cv::Scalar(50, 255, 255), matProcessed);//For detecting red color

 cv::inRange(matOriginal, cv::Scalar(121,100,173), cv::Scalar(129,137,255), matProcessed);//For detecting blue color

/////////////////////////////////////////////////////////////////////////////////////////////
  cv::GaussianBlur(matProcessed, matProcessed, cv::Size(9, 9), 1.5);//Applies filter to the proccessed image

/////////////////////////////////Detection of Objects////////////////////////////////////////////////////

  cv::HoughCircles(matProcessed, vecCircles, CV_HOUGH_GRADIENT, 2, matProcessed.rows / 4, 100, 100, 75, 125);//Detects the center and radii of the circles and logs them into the vector vecCircles


/////////////////////////////////////////////////////////////////////////////////////////////////////////

 // itrCircles[0] -> x itrCircles[1] -> y itrCircles[2] -> radius of the detected circle

  for(itrCircles = vecCircles.begin() ; itrCircles != vecCircles.end() ; itrCircles++){//Prints the radius, x and y coordinates of the circle to QPlainTextEdit in a formatted way
      ui->txtXYRadius->appendPlainText(QString("Ball position x =") + QString::number((*itrCircles)[0]).rightJustified(4, ' ') +
          QString(", y =") + QString::number((*itrCircles)[1]).rightJustified(4, ' ') +
          QString(", radius =") + QString::number((*itrCircles)[2], 'f', 3).rightJustified(7, ' '));


      cv::circle(matOriginal, cv::Point((int)(*itrCircles)[0], (int)(*itrCircles)[1]), 3, cv::Scalar(0, 255, 0), CV_FILLED);//Marks the center of the circle with a green dot
      cv::circle(matOriginal, cv::Point((int)(*itrCircles)[0], (int)(*itrCircles)[1]), (int)(*itrCircles)[2], cv::Scalar(0, 0, 255), 3);//Marks the circumference of the circle with red


     // cv::cvtColor(matOriginal, matOriginal, CV_BGR2RGB);//Changes the color standarts of the image from Blue-Green-Red to Red-Green-Blue

      QImage qimgOriginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);//Turns OpenCV image into QImage
      QImage qimgProcessed((uchar*)matProcessed.data, matProcessed.cols, matProcessed.rows, matProcessed.step, QImage::Format_Indexed8);//Turns OpenCV image into QImage

      ui->lblOriginalImage->setPixmap(QPixmap::fromImage(qimgOriginal));//Displays image with circle's markings on lblOriginalImage
      ui->lblProcessedImage->setPixmap(QPixmap::fromImage(qimgProcessed));//Displays processed image on lblProcessedImage

    }

}

void MainWindow::on_pushButton_Pause_clicked()//Pauses the Application
{
  if((manageTimer%2)){
      tmrTimer->start();
      ui->pushButton_Pause->setText("Pause");

    }

  if(!(manageTimer%2)){
    tmrTimer->stop();
    ui->pushButton_Pause->setText("Start");
    }

  manageTimer++;
}

void MainWindow::on_pushButton_Exit_clicked()//Terminates the Application
{
    QApplication::exit();
}
