import QtQuick 2.4
import "."

SettingControl {
    id: root
    implicitHeight: childrenRect.height

    property alias placeholder: edit.placeholder
    property alias validation: edit.validator
    property alias value: edit.text
    property alias suggestedWidthString: edit.suggestedWidthString
    property alias useFullWidth: edit.useFullWidth
    property string defaultValue: ""

    function apply()
    {
        if (option != "") {
            _config.setArg(option, value)
        }
    }

    LineEdit {
        id: edit
        label: root.label
        width: parent.width
    }

    SettingDescription {
        id: description
        enabled: root.enabled
        text: root.description
        anchors.top: edit.bottom
        anchors.topMargin: Style.margin
        width: parent.width
    }
}