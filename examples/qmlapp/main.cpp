//============================================================================
/// \file   main.cpp
/// \author Uwe Kindler
/// \date   08.01.2015
/// \brief  main of virtual keyboard example application
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include <QQuickView>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFont>
#include <QFontDatabase>
#include <QDebug>
#include <QScreen>
#include <QDir>

#include <QtPlugin>
Q_IMPORT_PLUGIN(QsgEpaperPlugin)

/**
 * main entry point for application
 */
int main(int argc, char *argv[])
{
    qputenv("QMLSCENE_DEVICE", "epaper");
    qputenv("QT_QPA_PLATFORM", "epaper:enable_fonts");
    qputenv("QT_QPA_EVDEV_TOUCHSCREEN_PARAMETERS", "rotate=180");
    // Load virtualkeyboard input context plugin
    qputenv("QT_IM_MODULE", QByteArray("freevirtualkeyboard"));

    QGuiApplication app(argc, argv);

    // Set standard font so that application looks equal on all platforms
    QFontDatabase FontDatabase;
    FontDatabase.addApplicationFont(":/DejaVuSans.ttf");
    app.setFont(QFont("DejaVu Sans"));
    app.setObjectName("QGuiApplication");

    qDebug() << "DEPLOYMENT_PATK:" << QDir(DEPLOYMENT_PATH).absolutePath();

    QQuickView view;
    //QQmlContext *rootContext = view.rootContext();
    view.rootContext()->setContextProperty("screenPixelDensity",
                                    QGuiApplication::primaryScreen()->physicalDotsPerInch());
    view.rootContext()->setContextProperty("screenGeometry",
                                    app.primaryScreen()->geometry());
    view.setSource(QDir(DEPLOYMENT_PATH).filePath("Main.qml"));
    view.setObjectName("QQuickView");
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.engine()->setObjectName("QQuickEngine");
    view.engine()->addImportPath(qApp->applicationDirPath());
    qDebug() << "qApp->applicationDirPath" << qApp->applicationDirPath();

    // Set size to 800 x 480 WXGA - this is the size of the upcoming Manga
    // screen.
    view.setWidth(1280);
    view.setHeight(800);

    view.show();

    return app.exec();
}
