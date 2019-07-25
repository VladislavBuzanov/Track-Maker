.import QtQuick.LocalStorage 2.0 as QQLS

var _database = QQLS.LocalStorage.openDatabaseSync("Journal", "1.0")
_database.transaction(function (tx) {
    tx.executeSql("CREATE TABLE IF NOT EXISTS Journal(\
        id INTEGER PRIMARY KEY AUTOINCREMENT,\
        date TEXT,\
        coords TEXT,\
        time TEXT
        )");
});

function append(properties) {
    _database.transaction(function (tx) {
        var journalInsertResult = tx.executeSql("INSERT INTO Journal(date, coords, time) VALUES(?, ?, ?)",
                                              [properties.date, properties.coords, properties.time]);
        properties.id = parseInt(journalInsertResult.insertId);});
    return properties;
}

function remove(id) {
    _database.transaction(function (tx) {
        tx.executeSql("DELETE FROM Journal WHERE id = ?",
                      [id]);
    });
}

function set(id, properties) {
    _database.transaction(function (tx) {
        tx.executeSql("UPDATE Journal SET date = ?, coords = ?, time = ? WHERE ID = ?",
        [properties.date, properties.coords, properties.time, id]);
    });
    return properties;
}

function readAll() {
    var journalSelectRows;
    _database.readTransaction(function(tx) {
        var journalSelectResult = tx.executeSql("SELECT * FROM Journal ORDER BY id ASC");
        journalSelectRows = journalSelectResult.rows;
    });
    var journal = [];
    for (var iNoteRow = 0; iNoteRow < journalSelectRows.length; ++iNoteRow) {
        var journalItem = journalSelectRows.item(iNoteRow);
        journal[journalItem.id] = {
            id: parseInt(journalItem.id),
            date: journalItem.date,
            coords: journalItem.coords,
            time : journalItem.time
        };
    }
    return journal.filter(function (note) { return note !== undefined });
}
