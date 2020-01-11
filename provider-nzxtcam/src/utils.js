function camelCase(...segments) {
    if (segments.length === 0)
        return "";

    let output = segments[0];
    for (let i=1; i<segments.length; i++) {
        let segment = (
            segments[i].substring(0, 1).toUpperCase() +
            segments[i].substring(1));
        output += segment;
    }

    return output;
}

module.exports = {
    camelCase
};