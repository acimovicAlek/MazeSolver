/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *height_lbl;
    QLineEdit *width_entry;
    QLabel *width_lbl;
    QLineEdit *height_entry;
    QLabel *solver_lbl;
    QComboBox *solver_combo;
    QPushButton *generateMaze_btn;
    QLabel *mazeView;
    QPushButton *solve_btn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 10, 781, 561));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        height_lbl = new QLabel(layoutWidget);
        height_lbl->setObjectName(QStringLiteral("height_lbl"));

        verticalLayout->addWidget(height_lbl);

        width_entry = new QLineEdit(layoutWidget);
        width_entry->setObjectName(QStringLiteral("width_entry"));

        verticalLayout->addWidget(width_entry);

        width_lbl = new QLabel(layoutWidget);
        width_lbl->setObjectName(QStringLiteral("width_lbl"));

        verticalLayout->addWidget(width_lbl);

        height_entry = new QLineEdit(layoutWidget);
        height_entry->setObjectName(QStringLiteral("height_entry"));

        verticalLayout->addWidget(height_entry);

        solver_lbl = new QLabel(layoutWidget);
        solver_lbl->setObjectName(QStringLiteral("solver_lbl"));

        verticalLayout->addWidget(solver_lbl);

        solver_combo = new QComboBox(layoutWidget);
        solver_combo->setObjectName(QStringLiteral("solver_combo"));

        verticalLayout->addWidget(solver_combo);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        generateMaze_btn = new QPushButton(layoutWidget);
        generateMaze_btn->setObjectName(QStringLiteral("generateMaze_btn"));

        gridLayout->addWidget(generateMaze_btn, 1, 1, 1, 1);

        mazeView = new QLabel(layoutWidget);
        mazeView->setObjectName(QStringLiteral("mazeView"));
        mazeView->setEnabled(true);
        mazeView->setMinimumSize(QSize(200, 200));
        mazeView->setFrameShape(QFrame::Box);
        mazeView->setFrameShadow(QFrame::Sunken);
        mazeView->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(mazeView, 0, 0, 3, 1);

        solve_btn = new QPushButton(layoutWidget);
        solve_btn->setObjectName(QStringLiteral("solve_btn"));
        solve_btn->setEnabled(false);

        gridLayout->addWidget(solve_btn, 2, 1, 1, 1);

        gridLayout->setColumnMinimumWidth(0, 620);
        gridLayout->setColumnMinimumWidth(1, 150);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        solver_combo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Maze Simulator", 0));
        height_lbl->setText(QApplication::translate("MainWindow", "Maze Height:", 0));
        width_entry->setText(QApplication::translate("MainWindow", "21", 0));
        width_lbl->setText(QApplication::translate("MainWindow", "Maze Width:", 0));
        height_entry->setText(QApplication::translate("MainWindow", "25", 0));
        solver_lbl->setText(QApplication::translate("MainWindow", "Solver:", 0));
        solver_combo->clear();
        solver_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Backtracking", 0)
         << QApplication::translate("MainWindow", "MODAL_LOGIC", 0)
         << QApplication::translate("MainWindow", "DFS", 0)
         << QApplication::translate("MainWindow", "A* search", 0)
        );
        solver_combo->setCurrentText(QApplication::translate("MainWindow", "Backtracking", 0));
        generateMaze_btn->setText(QApplication::translate("MainWindow", "Generate\n"
"Maze", 0));
        mazeView->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        solve_btn->setText(QApplication::translate("MainWindow", "Solve\n"
"Maze", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
