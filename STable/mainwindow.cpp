#include "mainwindow.h"

extern vector <vector<QString>> segments;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){



   mainWidget = new QWidget;
   mainLayout = new QHBoxLayout;
   firstLayout = new QVBoxLayout;
   secondLayout = new QVBoxLayout;
   editFieldsLayout = new QHBoxLayout;

   algorithm = new QComboBox(this);




   holeTable = new QTableWidget(this);
   holeTable ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

   myTable = new QTableWidget(this);
   myTable ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

   addPID = new QPushButton;
   processSelectLabel = new QLabel();
   processSelect = new QComboBox(this);
   deallocatePID = new QPushButton;

   segmentTable = new QTableWidget(this);
   segmentTable ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

   start = new QPushButton;
   remove = new QPushButton;
   reset = new QPushButton;
   Quantum = new QLabel;
   quantumValue=new QLineEdit;
   holesNumber = new QLineEdit;



   quantumValue->setPlaceholderText("Enter Memory Size");
   holesNumber->setPlaceholderText("Enter Number of Holes");


   algorithm->addItem("First Fit",0);
   algorithm->addItem("Best Fit",1);
   addPID->setText("Add PID");
   processSelectLabel->setText("Select a Process to Deallocate");
   start->setText("Start");
   deallocatePID->setText("Deallocate Process");
   remove->setText("Remove Last PID");
   reset->setText("Reset");
   Quantum->setText("Enter Memory Size");

   //====================================


    renderArea = new RenderArea;
    renderArea->setShape(RenderArea::Rect);
    renderArea->setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    renderArea->setBrush(QBrush(Qt::green, Qt::SolidPattern	));
   //=====================================

   draw();
   connect(addPID,SIGNAL(pressed()),this,SLOT(on_add_clicked()));
   connect(holesNumber,SIGNAL(textChanged(const QString)),this,SLOT(on_holesNumber_Changed(QString)));
   connect(reset,SIGNAL(pressed()),this,SLOT(on_reset_clicked()));
   connect(remove,SIGNAL(pressed()),this,SLOT(on_remove_clicked()));
   connect(myTable,SIGNAL(itemChanged(QTableWidgetItem *)),this,SLOT(on_myTable_itemChanged(QTableWidgetItem *)));
   connect(start,SIGNAL(pressed()),this,SLOT(on_start_clicked()));
   connect(algorithm,SIGNAL(activated(int)),this,SLOT(on_algorithm_change(int)));
   connect(processSelect,SIGNAL(activated(int)),this,SLOT(on_processSelect_change(int)));
   this->setStyleSheet("QPushButton{height:40px;font-size:20px;background:#ff6363;"
                       "border-radius:15px;"
                       "}QPushButton:hover{}"
                       "MainWindow{background-color:#ffbd69;}"
                       "QTableWidget{}"
                       "QChart{background-color:#ffbd69;}"
                       "QComboBox{height:33px;"
                       "font-size:20px;}"
                       "QLabel{font-size:20px;}"
                       "QLineEdit{font-size:11px;}");
}

void MainWindow::draw(){


    myTable->setColumnCount(2);
    myTable->setHorizontalHeaderLabels({"PID","Number of Segments"});


    holeTable->setColumnCount(3);
    holeTable->setHorizontalHeaderLabels({"Hole Number","Base","Limit"});

    segmentTable->setColumnCount(3);
    segmentTable->setHorizontalHeaderLabels({"PID","Segment Name","size"});

    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);




    mainLayout->addLayout(firstLayout);
    firstLayout->addWidget(algorithm);
    firstLayout->addLayout(editFieldsLayout);


    editFieldsLayout->addWidget(quantumValue);
    editFieldsLayout->addWidget(holesNumber);


    firstLayout->addWidget(holeTable);
    firstLayout->addWidget(start);

    firstLayout->addWidget(remove);
    firstLayout->addWidget(reset);
    mainLayout->addLayout(secondLayout);

    secondLayout->addWidget(myTable);
    secondLayout->addWidget(addPID);
    secondLayout->addWidget(processSelectLabel);
    secondLayout->addWidget(processSelect);
    secondLayout->addWidget(deallocatePID);

    mainLayout->addWidget(segmentTable);
    //segmentTable->verticalScrollBar()->setDisabled(true);

    mainLayout->addWidget(renderArea);

    setWindowIcon(QIcon(":images/myappico.ico"));
    setWindowTitle("Scheduler");
    resize(QDesktopWidget().availableGeometry(this).size() * 0.6);

}


MainWindow::~MainWindow(){
}




void MainWindow::on_holesNumber_Changed(const QString &text){
    holeTable->setRowCount(text.toInt());
    segmentTableData.resize(segmentTableData.size()+1);

}


void MainWindow::on_add_clicked(){


    myTable->setRowCount(myTable->rowCount()+1);
    segmentTableData.resize(segmentTableData.size()+1);

}

void MainWindow::on_remove_clicked(){
    if(!segmentTableData.empty()){
        myTable->setRowCount(myTable->rowCount()-1);
        segmentTableData.resize(segmentTableData.size()-1);
    }
}

void MainWindow::on_myTable_itemChanged(QTableWidgetItem *item)
{
    QString temp  =item->text();
    int pos =0;

    QIntValidator v(1,100000);


    if(myTable->currentColumn() ==0){
        if(PIDS.find(temp) != PIDS.end() || temp=="" ){
            QMessageBox messageBox;
//          messageBox.setFixedSize(1200,800);
            messageBox.critical(0,"Error","You Have Entered a duplicate PID\nPlaese Enter a Unique PID");
            item->setText("edit PID");
        }
        else if(temp!="edit PID"){
            PIDS.insert(temp);
            processSelect->addItem(temp);
            if(deallocatePID->text()=="Deallocate Process"){
                deallocatePID->setText("Deallocate Process "+temp);
            }
        }

    }
    else{
        if(v.validate(temp,pos) == QValidator::Invalid || v.validate(temp,pos) == QValidator::Intermediate){
            QMessageBox messageBox;
//            messageBox.setFixedSize(800,400);
            messageBox.critical(0,"Error","Please enter a valid Integer Number");
            item->setText("1");
        }
        else{
            //segmentTable->setRowCount(segmentTable->rowCount() + temp.toInt());
        }
    }

    //data[myTable->currentRow()][myTable->currentColumn()] =  temp.toStdString().c_str();
}

void MainWindow::on_start_clicked(){
    QVariant selected = algorithm->itemData(algorithm->currentIndex());
    result.clear();
    if(selected ==0){

    }
    else if(selected ==1){

    }
    else if(selected ==2){

    }
    else if(selected ==3){

    }
    else if(selected == 4){

    }
    else if(selected ==5){

    }
    //colorGenerator();
    for(unsigned int i=0;i<result.size();i++){
        getAndAssignColor(result[i][0]);
    }
}

void MainWindow::on_algorithm_change(int index){
    //data.clear();
    //myTable->setRowCount(0);
    if(index==0 ||index==3||index==4||index==5){
    }
    else{
    }

}

void MainWindow::on_processSelect_change(int index){
    deallocatePID->setText(QString("Deallocate Process ")+ processSelect->itemText(index));
}


void MainWindow::on_reset_clicked(){

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
/*
    myTable->setRowCount(0);
    myTable->setColumnCount(0);
    data.clear();
    result.clear();
    ganttChart->setRowCount(0);
    ganttChart->setColumnCount(0);
    draw();*/
}


QColor getAndAssignColor(int pid){
    if(ProcessColors.find(pid) == ProcessColors.end()){
        ProcessColors[pid]= QColor(Palette[numOfUsedColors%Palette.size()]);
        return Palette[numOfUsedColors++%Palette.size()];
    }
    else {
        return ProcessColors[pid];
    }
}

void colorGenerator(int colorsNumber){
    Palette.clear();
    ProcessColors.clear();
    numOfUsedColors =0;
    for(unsigned int i=0;i<colorsNumber;i++){
        unsigned int degree = 360 /colorsNumber*i;
        Palette.push_back(QColor::fromHsv(degree,255,255));
    }
}
