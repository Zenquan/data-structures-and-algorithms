var nNode = /** @class */ (function () {
    function nNode(element) {
        element;
        this.next = null;
    }
    return nNode;
}());
var LinkedList = /** @class */ (function () {
    function LinkedList() {
        this.length = 0;
        this.head = null;
    }
    LinkedList.prototype.append = function (element) {
        var newNode = new nNode(element);
    };
    return LinkedList;
}());
