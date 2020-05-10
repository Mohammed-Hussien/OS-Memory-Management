#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QProcess>
#include "renderarea.h"
#include "mainwindow.h"
#include <set>
vector <vector<QString>> segments(9);
QMap<int,QColor> ProcessColors;
QVector<QColor> Palette;
vector <vector<string> >segmentTableData ;
vector <vector<float>> result;
set <QString> PIDS;
int numOfUsedColors=0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
