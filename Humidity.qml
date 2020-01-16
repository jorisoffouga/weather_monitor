import QtQuick 2.12
import QtCharts 2.3

ChartView {
    antialiasing: true
    BarSeries {
        axisY : ValueAxis {
            min: 0
            max: 100
            tickCount: 10
        }
        axisX: BarCategoryAxis {
            categories: ["Humidity"]
        }
        BarSet {
            label: "Humidity";
            values: weatherMonitor.qmlGetHumidity
        }
    }
}
