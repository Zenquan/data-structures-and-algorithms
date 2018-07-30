"use strict";
exports.__esModule = true;
var Stack = /** @class */ (function () {
    function Stack(list) {
        this.list = list;
    }
    Stack.prototype.push = function (el) {
        this.list.push(el);
    };
    Stack.prototype.pop = function () {
        return this.list.pop();
    };
    Stack.prototype.peek = function () {
        return this.list[this.list.length - 1];
    };
    Stack.prototype.isEmpty = function () {
        return this.len() === 0;
    };
    Stack.prototype.len = function () {
        return this.list.length;
    };
    Stack.prototype.clear = function () {
        return this.list = [];
    };
    return Stack;
}());
exports["default"] = Stack;
