/*
 * Copyright (c) 2020-2023 LG Electronics Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

import QtQuick 2.4
import WebOSServices 1.0
import Eos.Window 0.1
import PmLog 1.0
import Source.cpp

WebOSWindow {
    id: root
    width: 1920
    height: 1080
    visible: true
    appId: "com.domain.app"
    title: "QML app"
    color: "lightblue"
    displayAffinity: params["displayAffinity"]

    Text {
        id: mainText
        anchors.centerIn: parent
        font.family: "Helvetica"
        font.pointSize: 50
        text: "Reminder"
    }

    Column {
	spacing: 10
	anchors.centerIn: parent

   TextField {
	id: inputField
	width: parent.width * 0.8
	placeholderText: "Введите текст"
    }

    Button {
	text: "Отправить"
	onClicked: {
	
		myCppFunction(inputField.text)
	}
}
}


    property var launchParams: params
    onLaunchParamsChanged: {
        pmLog.info("LAUNCH_PARAMS", {"params": launchParams})
    }

    Service {
        id: systemService
        appId: "com.domain.app"

        function getTime() {
            call("luna://com.webos.service.systemservice","/clock/getTime","{}")
        }

        onResponse: {
            var jsonObject = JSON.parse(payload);
            pmLog.info("GETTIME", {"utc": jsonObject.utc});
            mainText.text = "UTC : " + jsonObject.utc
        }

        onError: {
            var jsonObject = JSON.parse(payload);
            pmLog.error("GETTIME", {"error": jsonObject});
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: systemService.getTime()
    }

    onWindowStateChanged: {
        pmLog.info("WINDOW_CHANGED", {"status": windowState})
    }

    PmLog {
        id: pmLog
        context: "QMLApp"
    }
}
