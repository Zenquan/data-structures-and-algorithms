var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
//push:在数组末尾插入元素，返回新数组，改变原数组
arr.push(-1);
arr.push(-1, -3);
alert(arr);
//pop:去除最末尾的元素，返回去除掉的元素，改变原数组
arr.pop();
alert(arr);
//unshift:在开始插入元素，返回新数组，改变原数组
arr.unshift(0, 0);
alert(arr);
//shift:去除最开始的元素，返回去除掉的元素，改变原数组
arr.shift();
alert(arr);
