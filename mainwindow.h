#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_pushButton_Pause_clicked();

  void on_pushButton_Exit_clicked();

private:
  Ui::MainWindow *ui;

  cv::VideoCapture capWebcam;//Captures image from webcam
  cv::Mat matOriginal;//Original Image
  cv::Mat matProcessed;//Processed Image

  QImage qimOriginal;//Original Image to be displayed
  QImage qimProcessed;//Processed Image to be displayed

  std::vector<cv::Vec3f> vecCircles;//Stores the location, and the radii of detected circles
  std::vector<cv::Vec3f>::iterator itrCircles;//Iterator which browses vecCircles

  QTimer* tmrTimer;//Timer to update Image display

  int manageTimer;//Manages the Pause button's behevior


public slots:
    void processFrameandUpdateGUI();
};

#endif // MAINWINDOW_H
