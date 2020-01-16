import QtQuick 2.12
import QtCharts 2.3

ChartView {
    antialiasing: true
    BarSeries {
        axisY : ValueAxis {
            min: 0
            max: 1000
            tickCount: 40
        }
        axisX: BarCategoryAxis {
            categories: ["Pressure"]
        }
        BarSet {
            label: "Pressure";
            values: weatherMonitor.qmlGetPressure
        }
    }
}
