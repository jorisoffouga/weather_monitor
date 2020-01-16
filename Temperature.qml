import QtQuick 2.12
import QtCharts 2.3

ChartView {
    antialiasing: true
    BarSeries {
        axisY : ValueAxis {
            min: 0
            max: 100
            tickCount: 15
        }
        axisX: BarCategoryAxis {
            categories: ["Temperature"]
        }
        BarSet {
            label: "Temperature";
            values: weatherMonitor.qmlGetTemperature
        }
    }
}
