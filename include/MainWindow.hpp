#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>

class MainWindow : public QMainWindow {
        // macro to signal qt to generate extra code for some qt features
        Q_OBJECT

        public:
                MainWindow();

        private:
                QHBoxLayout* barLayout;
                QVBoxLayout* mainLayout;
                QWidget* barWidget;
                QWidget* central;
                QWidget* mainWidget;
                QPushButton* saveButton;
                QPushButton* openButton;
                QPushButton* homeButton;



};
