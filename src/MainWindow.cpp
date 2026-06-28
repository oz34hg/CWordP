#include <QMainWindow>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include "MainWindow.hpp"

MainWindow::MainWindow() {
        resize(1200, 720);
        setWindowTitle("CWordP");

        // set all the buttons for the menu bar
        homeButton = new QPushButton("Home");
        openButton = new QPushButton("Open Document");
        saveButton = new QPushButton("Save Document");

        // set up the main widget to display the content of the currently choosen tab
        central = new QWidget(this);

        // set up the layout to control the whole screen
        mainLayout = new QVBoxLayout(central);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(0);

        // Bar widget
        barWidget = new QWidget;
        barWidget->setFixedHeight(40);

        barLayout = new QHBoxLayout(barWidget);
        barLayout->addWidget(homeButton);
        barLayout->addWidget(openButton);
        barLayout->addWidget(saveButton);

        // Main content
        mainWidget = new QWidget;

        // Add widgets to main layout
        mainLayout->addWidget(barWidget);
        mainLayout->addWidget(mainWidget);

        setCentralWidget(central);

        
}
