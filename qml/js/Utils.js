function listToArray(list) {
    var array = [];
    for (var i = 0; i < list.count; ++i) {
        array[i] = list.get(i);
    }
    return array;
}

function fillListModel(model, array) {
    array.forEach(function (item) {
        model.append(item);
    });
}

function normalizeProperties(properties, defaultValues) {
    var keys = Object.keys(defaultValues);
    var normalizedProperties = {};
    keys.forEach(function (key) {
        if (properties[key] === undefined) {
            normalizedProperties[key] = defaultValues[key];
        } else {
            normalizedProperties[key] = properties[key];
        }
    });
    return normalizedProperties;
}

function  filterProperties(properties, keys) {
    var filteredProperties = {};
    keys.forEach(function (key) {
        if (properties[key] !== undefined) {
            filteredProperties[key] = properties[key];
        }
    });
    return filteredProperties;
}
