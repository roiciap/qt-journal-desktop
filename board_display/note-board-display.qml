import QtQuick 2.15

import QtQuick.Controls
Rectangle {
    id: mainRect
    width: 200
    height: 200
    color: "yellow"
    border.color: "gray" // Ustawienie koloru obramówki
    border.width: 2 // Ustawienie grubości obramówki

    // property alias text: noteText.text
    Rectangle{
        opacity: 0.5
        height: 30
        anchors.top: mainRect.top
        id: topBar
        color: "black"
        width: mainRect.width
        MouseArea {
            id: dragArea
            anchors.fill: parent
            drag.target: mainRect
            onPositionChanged:{
                noteLogic.moved(mainRect.x, mainRect.y);
                mainRect.x = 0;
                mainRect.y = 0;
            }
        }
    }

    Rectangle{
        id: button1
        width:20
        height: 20
        color: "red"
        anchors.top: mainRect.top
        anchors.topMargin: 20
        anchors.right: mainRect.right
    }

    Rectangle{
        id: button2
        width:20
        height: 20
        color: "blue"
        anchors.bottom: mainRect.bottom
        anchors.bottomMargin: 20
        anchors.right: mainRect.right
        // MouseArea {
        //     anchors.fill: parent
        //     onClicked: {
        //         board.onEdit(myNoteLogic);
        //     }
        // }
    }



    // Text {
    //     id: noteText
    //     anchors.top: mainRect.top
    //     anchors.topMargin: 30
    //     anchors.leftMargin: 10
    //     anchors.left: mainRect.left
    //     anchors.rightMargin: 30
    //     anchors.fill: parent
    //     text: myNoteLogic.text
    //     wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    //     elide: Text.ElideRight
    // }

}
