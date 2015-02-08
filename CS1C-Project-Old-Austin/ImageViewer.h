#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QPrinter>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QScreen>
#include <QImageReader>
#include <QStandardPaths>


namespace Ui {
class ImageViewer;
}

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer();
    ~ImageViewer();
    bool loadFile(const QString &);

private slots:
       // void on_Picture_windowIconChanged(const QIcon &icon);
        void open();
       // void print();
        void zoomIn();
        void zoomOut();
        void normalSize();
        void fitToWindow();
        //void about();

private:
    void createActions();
    void createMenus();
    void updateActions();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor;


    #ifndef QT_NO_PRINTER
        QPrinter printer;
    #endif

       QAction *openAct;
       QAction *printAct;
       QAction *exitAct;
       QAction *zoomInAct;
       QAction *zoomOutAct;
       QAction *normalSizeAct;
       QAction *fitToWindowAct;
       QAction *aboutAct;
       QAction *aboutQtAct;
       QMenu   *fileMenu;
       QMenu   *viewMenu;
       QMenu   *helpMenu;
};

#endif // IMAGEVIEWER_H
