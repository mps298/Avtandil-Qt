#include "mainwindow.h"

#include <QApplication>
#include <QTime>
#include <QTranslator>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
//       QTextCodec::setCodecForTr(codec);
//       QTextCodec::setCodecForCStrings(codec);
       QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);

    qsrand(static_cast<uint>(QTime::currentTime().msec()));

    QTranslator translator;
    qDebug()<< "translation loaded = "<<translator.load(QLocale::Russian, "avtandil1956", "_");
    a.installTranslator(&translator);


    MainWindow w;
    w.show();
//    connect(&w, SIGNAL())
    w.pinSlot();
    return a.exec();
}
