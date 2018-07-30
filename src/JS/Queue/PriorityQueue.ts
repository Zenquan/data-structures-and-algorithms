class PriorityQueue<T> {
    private list: T[]
    constructor(list: T[]) {
        this.list = list;
    }
    public enQueue(priority, element) {
        let queueElement = new QueueElement(priority, element);
        if (this.isEmpty()) {
            this.list.push(queueElement);
        } else {
            let added: boolean = false;
            let _that = this;
            this.list.every(function(index, item) {
                if (queueElement.priority < item.priority) {
                    _that.list.splice(index, 0, queueElement);
                    added = true;
                    return false;
                }
            })
            if (!added) {
                this.list.push(queueElement);
            }
        }
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

function QueueElement<T>(priority, element){
        this.priority = priority;
        this.element = element;
}
