var PriorityQueue = /** @class */ (function () {
    function PriorityQueue(list) {
        this.list = list;
    }
    PriorityQueue.prototype.enQueue = function (priority, element) {
        var queueElement = new QueueElement(priority, element);
        if (this.isEmpty()) {
            this.list.push(queueElement);
        }
        else {
            var added_1 = false;
            var _that_1 = this;
            this.list.every(function (index, item) {
                if (queueElement.priority < item.priority) {
                    _that_1.list.splice(index, 0, queueElement);
                    added_1 = true;
                    return false;
                }
            });
            if (!added_1) {
                this.list.push(queueElement);
            }
        }
    };
    PriorityQueue.prototype.deQueue = function () {
        return this.list.shift();
    };
    PriorityQueue.prototype.front = function () {
        return this.list[0];
    };
    PriorityQueue.prototype.isEmpty = function () {
        return this.list.length === 0;
    };
    PriorityQueue.prototype.len = function () {
        return this.list.length;
    };
    PriorityQueue.prototype.clear = function () {
        return this.list = [];
    };
    return PriorityQueue;
}());
function QueueElement(priority, element) {
    this.priority = priority;
    this.element = element;
}
