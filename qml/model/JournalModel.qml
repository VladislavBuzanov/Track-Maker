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
        var notes = Database.readAll();
        Utils.fillListModel(model, notes);
    }
}
