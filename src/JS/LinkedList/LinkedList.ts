class nNode<T>{
    next: T
    constructor(element: T){
        element;
        this.next = null;
    }
}
class LinkedList<T> {
    length: number;
    head: object;
    constructor(){
       this.length = 0
       this.head = null; 
    }
    append(element: T) {
        let newNode = new nNode(element);
        if(this.head===null){
            this.head = nNode;
        }
    }
}