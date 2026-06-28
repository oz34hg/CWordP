#include <QMainWindow>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include "MainWindow.hpp"

MainWindow::MainWindow() {
        resize(1200, 720);
        setWindowTitle("CWordP");
        
        textWidget = new QWidget;

        // set up the text test 
        textTest = new QLabel(this);
        textTest->setText("Hello World");
        textTest->setAlignment(Qt::AlignCenter);
        textTest->setFixedSize(500, 250);
        
        // set up the layout for the text test
        textTestLayout = new QVBoxLayout(textWidget);
        textTestLayout->addWidget(textTest, 0, Qt::AlignCenter);

        setCentralWidget(textWidget);

        
}
