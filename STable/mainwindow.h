#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <QWidget>
#include <QDesktopWidget>
#include <math.h>
#include <QScrollBar>
#include <QHBoxLayout>
#include <vector>
#include <QVBoxLayout>
#include <QProcess>
#include <QComboBox>
#include <QBarLegendMarker>
#include <QTableWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QTableWidget>
#include <QSlider>
#include <QLabel>
#include <QScrollArea>
#include <QSpinBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QMap>
#include <QPair>
#include <QPainter>
#include <QDebug>
#include <QComboBox>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/qchartview.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QValueAxis>
#include <renderarea.h>
#include <set>

QT_CHARTS_USE_NAMESPACE
using namespace  std;

extern QMap<int,QColor> ProcessColors;
extern QVector<QColor> Palette;
extern vector <vector<string> >segmentTableData ;
extern vector <vector<float>> result;
extern vector <vector<QString>> segments;
extern int numOfUsedColors;
extern set <QString> PIDS;




class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *mainWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout * firstLayout;
    QVBoxLayout * secondLayout;
    QComboBox * processSelect;
    QPushButton* deallocatePID;

    QHBoxLayout * editFieldsLayout;


    QTableWidget * myTable;
    QTableWidget * holeTable;
    QTableWidget * segmentTable;


    QComboBox * algorithm;
    QLabel * Quantum;
    QLineEdit * quantumValue;
    QLineEdit * holesNumber;

    QLabel * processSelectLabel;

    QPushButton * addPID;
    QPushButton * start;
    QPushButton * remove;
    QPushButton * reset;


//===========================================

    RenderArea *renderArea;






//=============================================


    void draw();
private slots:
    void on_holesNumber_Changed(const QString &text);
    void on_add_clicked();
    void on_remove_clicked();
    void on_myTable_itemChanged(QTableWidgetItem *item);
    void on_start_clicked();
    void on_reset_clicked();
    void on_algorithm_change(int);
    void on_processSelect_change(int);

};

void colorGenerator(int colorsNumber);
QColor getAndAssignColor(int pid);

#endif // MAINWINDOW_H