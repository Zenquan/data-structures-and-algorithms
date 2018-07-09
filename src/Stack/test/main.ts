interface type {
    decNum: number;
    dec2Bin(): string;
}
class dec2 implements type{
    decNum: number
    constructor(decNum: number) {
        this.decNum = decNum;
    }
    dec2Bin() {
        var stack = new stack([]);
        var remainer: number;
        while (this.decNum > 0) {
            remainer = this.decNum % 2;
            this.decNum = Math.floor(this.decNum / 2);
            stack.push(remainer);
        }
        var binArrString: string = '';
        while (!stack.isEmpty()) {
            binArrString += stack.pop;
        }
        return binArrString;
    }
} 

let d1 = new dec2(10);
alert(d1.dec2Bin());