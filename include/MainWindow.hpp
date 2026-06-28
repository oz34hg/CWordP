#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow {
        // macro to signal qt to generate extra code for some qt features

        Q_OBJECT

        public:
                MainWindow();

        private:
                QLabel *textTest;
                QVBoxLayout *textTestLayout;
                QWidget *textWidget;

};
