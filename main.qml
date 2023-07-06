/*
 * Copyright (c) 2020-2023 LG Electronics Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

import QtQuick 2.4
import WebOSServices 1.0
import QtQuick.Controls 2.15
import Eos.Window 0.1
import QtQuick.Layouts 1.15
import PmLog 1.0
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Notification App"

    // Модель для хранения данных
    ListModel {
        id: dataList
    }

    // Основная компоновка
    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        // Поле для записи данных (по центру экрана)
        TextField {
            id: inputField1
            placeholderText: "Введите данные"
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
        }

        // Поле для записи данных (в правом нижнем углу)
        TextField {
            id: inputField2
            placeholderText: "Введите сегодняшнюю дату"
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignRight | Qt.AlignBottom
        }

        // Кнопки
        RowLayout {
            spacing: 10

            Button {
                text: "Добавить"
                onClicked: {
                    dataList.append({text: inputField1.text})
                    inputField1.text = ""
                }
            }

            Button {
                text: "Удалить"
                onClicked: {
                    for (var i = 0; i < dataList.count; i++) {
                        if (dataList.get(i).text === inputField1.text) {
                            dataList.remove(i)
                            break
                        }
                    }
                    inputField1.text = ""
                }
            }

            Button {
                text: "Проверить"
                onClicked: {
                    var found = false
                    for (var i = 0; i < dataList.count; i++) {
                        if (dataList.get(i).text === inputField2.text) {
                            found = true
                            break
                        }
                    }
                    if (found) {
                        var notificationWindow = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Controls 2.15; ApplicationWindow { visible: true; width: 300; height: 200; title: "Уведомление"; Label { text: "У вас уведомления на сегодня" } }', parent)
                    } else {
                        inputField.text = ""
                    }
                }
            }
        }

        // Вывод данных из массива
        ListView {
            model: dataList
            delegate: Text {
                text: modelData.text
            }
        }
    }
}