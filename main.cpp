#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "WeatherMonitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    WeatherMonitor *weatherMonitor = new WeatherMonitor;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("weatherMonitor", weatherMonitor);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
