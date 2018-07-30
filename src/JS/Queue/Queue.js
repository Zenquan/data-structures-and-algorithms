var Queue = /** @class */ (function () {
    function Queue(list) {
        this.list = list;
    }
    Queue.prototype.enQueue = function (el) {
        this.list.push(el);
    };
    Queue.prototype.deQueue = function () {
        return this.list.shift();
    };
    Queue.prototype.front = function () {
        return this.list[this.list.length - 1];
    };
    Queue.prototype.isEmpty = function () {
        return this.list.length === 0;
    };
    Queue.prototype.len = function () {
        return this.list.length;
    };
    Queue.prototype.clear = function () {
        return this.list = [];
    };
    return Queue;
}());
