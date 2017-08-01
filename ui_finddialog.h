/********************************************************************************
** Form generated from reading UI file 'findDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *findLabel;
    QLineEdit *findText;
    QHBoxLayout *horizontalLayout_2;
    QLabel *replaceLabel;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *matchCaseCheckBox;
    QCheckBox *MatchEntireWordOnlyCheckBox;
    QCheckBox *regularExpressionCheckBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *searchBackWordsCheckBox;
    QCheckBox *warpAroundCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *closeButton;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;
    QPushButton *findButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(491, 237);
        verticalLayout_6 = new QVBoxLayout(Dialog);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        findLabel = new QLabel(Dialog);
        findLabel->setObjectName(QStringLiteral("findLabel"));

        horizontalLayout->addWidget(findLabel);

        findText = new QLineEdit(Dialog);
        findText->setObjectName(QStringLiteral("findText"));
        findText->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(findText);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        replaceLabel = new QLabel(Dialog);
        replaceLabel->setObjectName(QStringLiteral("replaceLabel"));

        horizontalLayout_2->addWidget(replaceLabel);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        matchCaseCheckBox = new QCheckBox(Dialog);
        matchCaseCheckBox->setObjectName(QStringLiteral("matchCaseCheckBox"));

        verticalLayout->addWidget(matchCaseCheckBox);

        MatchEntireWordOnlyCheckBox = new QCheckBox(Dialog);
        MatchEntireWordOnlyCheckBox->setObjectName(QStringLiteral("MatchEntireWordOnlyCheckBox"));

        verticalLayout->addWidget(MatchEntireWordOnlyCheckBox);

        regularExpressionCheckBox = new QCheckBox(Dialog);
        regularExpressionCheckBox->setObjectName(QStringLiteral("regularExpressionCheckBox"));

        verticalLayout->addWidget(regularExpressionCheckBox);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        searchBackWordsCheckBox = new QCheckBox(Dialog);
        searchBackWordsCheckBox->setObjectName(QStringLiteral("searchBackWordsCheckBox"));

        verticalLayout_2->addWidget(searchBackWordsCheckBox);

        warpAroundCheckBox = new QCheckBox(Dialog);
        warpAroundCheckBox->setObjectName(QStringLiteral("warpAroundCheckBox"));

        verticalLayout_2->addWidget(warpAroundCheckBox);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        closeButton = new QPushButton(Dialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_4->addWidget(closeButton);

        replaceButton = new QPushButton(Dialog);
        replaceButton->setObjectName(QStringLiteral("replaceButton"));

        horizontalLayout_4->addWidget(replaceButton);

        replaceAllButton = new QPushButton(Dialog);
        replaceAllButton->setObjectName(QStringLiteral("replaceAllButton"));

        horizontalLayout_4->addWidget(replaceAllButton);

        findButton = new QPushButton(Dialog);
        findButton->setObjectName(QStringLiteral("findButton"));

        horizontalLayout_4->addWidget(findButton);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_5);

        findLabel->raise();
        findText->raise();
        replaceLabel->raise();
        lineEdit->raise();
        closeButton->raise();
        replaceButton->raise();
        replaceAllButton->raise();
        findButton->raise();
        matchCaseCheckBox->raise();
        searchBackWordsCheckBox->raise();
        MatchEntireWordOnlyCheckBox->raise();
        regularExpressionCheckBox->raise();
        warpAroundCheckBox->raise();
        lineEdit->raise();
        lineEdit->raise();
#ifndef QT_NO_SHORTCUT
        findLabel->setBuddy(findText);
        replaceLabel->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        findLabel->setText(QApplication::translate("Dialog", "Find        ", Q_NULLPTR));
        replaceLabel->setText(QApplication::translate("Dialog", "Replace", Q_NULLPTR));
        matchCaseCheckBox->setText(QApplication::translate("Dialog", "Match case", Q_NULLPTR));
        MatchEntireWordOnlyCheckBox->setText(QApplication::translate("Dialog", "Match entire word only", Q_NULLPTR));
        regularExpressionCheckBox->setText(QApplication::translate("Dialog", "Regular expresson", Q_NULLPTR));
        searchBackWordsCheckBox->setText(QApplication::translate("Dialog", "Search backwords", Q_NULLPTR));
        warpAroundCheckBox->setText(QApplication::translate("Dialog", "Wrap around", Q_NULLPTR));
        closeButton->setText(QApplication::translate("Dialog", "Close", Q_NULLPTR));
        replaceButton->setText(QApplication::translate("Dialog", "Replace", Q_NULLPTR));
        replaceAllButton->setText(QApplication::translate("Dialog", "Rplace All", Q_NULLPTR));
        findButton->setText(QApplication::translate("Dialog", "Find", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
