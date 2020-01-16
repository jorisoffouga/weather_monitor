#ifndef WEATHERMONITOR_H
#define WEATHERMONITOR_H

#include <QtCore/QObject>
#include <QtDBus/QDBusConnection>
#include <QtCharts/QLineSeries>

class WeatherMonitor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList qmlGetTemperature READ getTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(QVariantList qmlGetPressure READ getPressure NOTIFY  pressureChanged)
    Q_PROPERTY(QVariantList qmlGetHumidity READ getHumidity NOTIFY  humidityChanged)

public:
    WeatherMonitor();
    ~WeatherMonitor();
public slots:
    void setWeatherInfos(QString value, int sensor_channel);

signals:
    void temperatureChanged();
    void humidityChanged();
    void pressureChanged();

private:
    QVariantList m_temp;
    QVariantList m_press;
    QVariantList m_hum;
    QVariantList getTemperature(){return m_temp;}
    QVariantList getHumidity(){return m_hum;}
    QVariantList getPressure(){return m_press;}
};
#endif // WEATHERMONITOR_H
