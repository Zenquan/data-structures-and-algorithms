class Stack<T> {
    private list: T[]

    constructor(list: T[]) {
        this.list = list;
    }
    public push(el: T) {
        this.list.push(el);
    }
    public pop(): T {
        return this.list.pop()
    }
    public peek(): T {
        return this.list[this.list.length - 1];
    }
    public isEmpty(): boolean {
        return this.len() === 0;
    }
    public len(): number {
        return this.list.length;
    }
    public clear(): T[] {
        return this.list = [];
    }
}

export default Stack;
