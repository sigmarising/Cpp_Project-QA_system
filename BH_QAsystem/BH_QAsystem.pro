#-------------------------------------------------
#
# Project created by QtCreator 2017-09-16T11:05:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BH_QAsystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        d_operate.cpp \
    BackEnd/source/Answer.cpp \
    BackEnd/source/BasicInfo.cpp \
    BackEnd/source/DataTime.cpp \
    BackEnd/source/FileHandle.cpp \
    BackEnd/source/QuesList.cpp \
    BackEnd/source/Question.cpp \
    BackEnd/source/SystemNeed.cpp \
    BackEnd/source/User.cpp \
    d_login.cpp \
    d_access.cpp \
    d_question.cpp \
    d_ask.cpp \
    d_answer.cpp \
    d_write.cpp \
    d_me.cpp \
    d_changekey.cpp \
    d_focus.cpp \
    d_focusfull.cpp \
    item_question.cpp \
    item_answer.cpp \
    item_focus.cpp \
    item_last.cpp

HEADERS += \
        d_operate.h \
    BackEnd/header/Answer.h \
    BackEnd/header/BasicInfo.h \
    BackEnd/header/Convert.h \
    BackEnd/header/DataTime.h \
    BackEnd/header/define.h \
    BackEnd/header/FileHandle.h \
    BackEnd/header/func.h \
    BackEnd/header/kernal.h \
    BackEnd/header/QuesList.h \
    BackEnd/header/Question.h \
    BackEnd/header/SystemNeed.h \
    BackEnd/header/User.h \
    d_login.h \
    d_alldialogs.h \
    d_access.h \
    d_question.h \
    d_ask.h \
    d_answer.h \
    d_write.h \
    d_me.h \
    d_changekey.h \
    d_focus.h \
    d_focusfull.h \
    item_question.h \
    item_answer.h \
    item_focus.h \
    item_last.h

FORMS += \
        d_operate.ui \
    d_login.ui \
    d_access.ui \
    d_question.ui \
    d_ask.ui \
    d_answer.ui \
    d_write.ui \
    d_me.ui \
    d_changekey.ui \
    d_focus.ui \
    d_focusfull.ui \
    item_question.ui \
    item_answer.ui \
    item_focus.ui \
    item_last.ui

RC_FILE = icon.rc

RESOURCES += \
    resource.qrc
