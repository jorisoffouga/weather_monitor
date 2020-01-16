#include "WeatherMonitor.h"
#include <QtDBus/QtDBus>
#include <QDebug>

WeatherMonitor::WeatherMonitor()
{
    m_temp.append(0);
    m_press.append(0);
    m_hum.append(0);

    if (!QDBusConnection::sessionBus().isConnected()) {
        qDebug()<< "Cannot connect to the D-Bus session bus.\n"
                   "To start it, run:\n"
                   "\teval `dbus-launch --auto-syntax`\n";
    }

    if (!QDBusConnection::sessionBus().registerService("org.weather.monitor")) {
        qDebug() << "Already Registered !";
    }

    QDBusConnection::sessionBus().registerObject("/", this, QDBusConnection::ExportAllContents);
}

WeatherMonitor::~WeatherMonitor()
{

}

void WeatherMonitor::setWeatherInfos(QString value, int sensor_channel)
{
    qDebug() << "Call setWeatherInfos with " << value.toDouble() << " " << sensor_channel;

    switch (sensor_channel) {
    case 0:
        m_temp.replace(0, value.toDouble());
        Q_EMIT temperatureChanged();
        break;
    case 1:
        m_press.replace(0, value.toDouble());
        Q_EMIT pressureChanged();
        break;
    case 2:
        m_hum.replace(0, value.toDouble());
        Q_EMIT humidityChanged();
        break;
    default:
        break;
    }
}
