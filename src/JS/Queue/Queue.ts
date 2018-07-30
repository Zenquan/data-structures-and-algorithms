class Queue<T>{
    private list: T[]
    constructor(list: T[]) {
        this.list = list;
    }
    public enQueue(el: T) {
        this.list.push(el);
    }
    public deQueue(): T {
        return this.list.shift();
    }
    public front(): T {
        return this.list[0];
    }
    public isEmpty(): boolean {
        return this.list.length === 0;
    }
    public len(): number {
        return this.list.length;
    }
    public clear(): T[] {
        return this.list = []
    }
}