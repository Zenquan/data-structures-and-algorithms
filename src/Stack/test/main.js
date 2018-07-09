var dec2 = /** @class */ (function () {
    function dec2(decNum) {
        this.decNum = decNum;
    }
    dec2.prototype.dec2Bin = function () {
        var stack = new stack([]);
        var remainer;
        while (this.decNum > 0) {
            remainer = this.decNum % 2;
            this.decNum = Math.floor(this.decNum / 2);
            stack.push(remainer);
        }
        var binArrString = '';
        while (!stack.isEmpty()) {
            binArrString += stack.pop;
        }
        return binArrString;
    };
    return dec2;
}());
var d1 = new dec2(10);
alert(d1.dec2Bin());
