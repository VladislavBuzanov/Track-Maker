import QtQuick 2.0
import "../js/JournalDB.js" as Database
import "../js/Utils.js" as Utils

ListModel {
    id: model

    function appendNote(properties) {
        var normalizedProperties = Utils.normalizeProperties(properties, {
            date: "",
            coords: "",
            time: ""
        });
        normalizedProperties = Database.append(normalizedProperties);
        append(normalizedProperties);
    }

    function removeNote(index) {
        var noteId = _noteIdByIndex(index);
        remove(index);
        Database.remove(noteId);
    }

    function getNote(index) {
        var note = get(index);
        return {
            date: note.date,
            coords: note.coords,
            time: note.time
        };
    }

    function setNote(index, properties) {
        var filteredProperties = Utils.filterProperties(properties, ["date", "coords", "time"]);
        filteredProperties = Database.set(_noteIdByIndex(index), filteredProperties);
        set(index, filteredProperties);
    }

    function _noteIdByIndex(index) {
        return get(index).id;
    }

    Component.onCompleted: {
        jmodel.appendNote(this.collectProperties())
        var notes = Database.readAll();
    }

    property string noteDate: "24/07/2019"
    property string noteCoords: "55.75269|48.74475,55.7556|48.74629,55.75567|48.75402,55.75051|48.75415"
    property string noteTime: "00:40"

    function getDate() {
        return noteDate
    }
    function getCoords() {
        return noteCoords
    }
    function getTime() {
        return noteTime
    }

    function collectProperties() {
        return {
            date: noteDate,
            coords: noteCoords,
            time: noteTime
        };
    }
}
