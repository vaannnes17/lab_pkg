#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings, true);

    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("Fusion"));

    QFont defaultFont = a.font();
    defaultFont.setStyleStrategy(QFont::PreferAntialias);
    a.setFont(defaultFont);

    MainWindow w;

    w.setAttribute(Qt::WA_TranslucentBackground, false);
    w.setAttribute(Qt::WA_NoSystemBackground, false);

    w.showMaximized();

    return a.exec();
}
