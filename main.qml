import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: "Weather Station Monitor"
    SwipeView {
        id: view
        anchors.fill: parent
        currentIndex: 0 //index par défaut
        Pressure {}
        Temperature {}
        Humidity {}
    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
