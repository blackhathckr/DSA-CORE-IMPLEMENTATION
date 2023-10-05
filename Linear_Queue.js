const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// DSA - Linear Queue Core Implementation

class LinearQueue {
    constructor(capacity) {
        this.capacity = capacity;
        this.front = 0;
        this.rear = -1;
        this.size = 0;
        this.linearQueue = new Array(this.capacity);
        console.log("Linear Queue of the Max Capacity: " + this.capacity + " Initialized \n");
    }

    isFull() {
        if (this.size > this.capacity) {
            console.log("Linear Queue is Full \n");
            return true;
        }
        else {
            console.log("Linear Queue is Not Full \n");
            return false;
        }
    }

    isEmpty() {
        if (this.front == 0 && this.rear == -1) {
            console.log("Linear Queue is Empty \n");
            return true;
        }
        else {
            console.log("Linear Queue is Not Empty \n");
            return false;
        }
    }

    getFront() {
        if (this.isEmpty()) {
            console.log("\n");
        }
        else {
            console.log("Linear Queue Front : " + this.front);
        }
    }

    getRear() {
        if (this.isEmpty()) {
            console.log("\n");
        }
        else {
            console.log("Linear Queue Rear : " + this.rear);
        }
    }

    // At Rear
    enqueue()  {
        if (this.isFull()) {
            console.log("\n");
            callback();
        }
        else {
            rl.question("Enter the Element to Enqueue \n", (ele) => {
                this.linearQueue[++this.rear] = ele;
                this.size += 1;
                console.log("Element " + ele + " Enqueued into the Linear Queue \n");
                LinearQueueImplmentation();
            })
        }
    }

    // At Front
    dequeue() {
        if (this.isEmpty()) {
            console.log("\n");
        }
        else {
            var ele = this.linearQueue[this.front++];
            this.size -= 1;
            console.log("Element " + ele + " Dequeued from the Linear Queue \n");
        }
    }

    reverseLinearQueue() {
        if (this.isEmpty()) {
            console.log("\n");
        }
        else {
            var start = this.front;
            var end = this.rear;
            while (start <= end) {
                var temp = this.linearQueue[start];
                this.linearQueue[start] = this.linearQueue[end];
                this.linearQueue[end] = temp;
                start++;
                end--;
            }
            console.log("Reversed the Linear Queue");
        }
    }

    searchLinearQueue() {
        if (this.isEmpty()) {
            console.log("\n");

        }
        else {

            rl.question("Enter the Element to Search for in the Linear Queue \n", (ele) => {
                var flag = 0;
                for (var i = 0; i < this.size; i++) {
                    if (ele == this.linearQueue[i]) {
                        console.log("Element " + ele + " Found in the Linear Queue \n");
                        flag++;
                        break;
                    }
                }
                if (flag == 0) {
                    console.log("Element " + ele + " Not Found in the Linear Queue \n");
                }
                LinearQueueImplmentation();
            });
        }
    }

    linearQueueElementsCount() {
        if (this.isEmpty()) {
            console.log("\n");
        }
        else {
            console.log("Linear Queue Elements Count : " + this.size);
        }
    }

    linearQueueElements() {
        if (this.isEmpty()) {
            console.log("\n");
        }
        else {
            console.log("Linear Queue Elements : ");
            for (var i = this.front; i <= this.rear; i++) {
                console.log(this.linearQueue[i]);
            }
        }
    }

    destructor() {
        console.log("Linear Queue Destroyed by Destructor \n");
    }
}



var linearQueue = new LinearQueue(100);

function LinearQueueImplmentation() {
    console.log("\n");
    console.log("DSA - Linear Queue Core Implementation \n");
    console.log(" ");
    console.log("Choose from the Following Options \n");
    console.log("1.isFull");
    console.log("2.isEmpty");
    console.log("3.Get Front");
    console.log("4.Get Rear");
    console.log("5.Enqueue");
    console.log("6.Dequeue");
    console.log("7.Reverse Linear Queue");
    console.log("8.Search Linear Queue");
    console.log("9.Linear Queue Elements Count");
    console.log("10.Linear Queue Elements");
    console.log("11.Exit \n");
    rl.question("", (input) => {
        const op = parseInt(input);
        switch (op) {
            case 1: linearQueue.isFull();
                LinearQueueImplmentation();
                break;

            case 2: linearQueue.isEmpty();
                LinearQueueImplmentation();
                break;

            case 3: linearQueue.getFront();
                LinearQueueImplmentation();
                break;

            case 4: linearQueue.getRear();
                LinearQueueImplmentation();
                break;

            case 5: linearQueue.enqueue();
                LinearQueueImplmentation();
                break;

            case 6: linearQueue.dequeue();
                LinearQueueImplmentation();
                break;

            case 7: linearQueue.reverseLinearQueue();
                LinearQueueImplmentation();
                break;

            case 8: linearQueue.searchLinearQueue();
                LinearQueueImplmentation();
                break;

            case 9: linearQueue.linearQueueElementsCount();
                LinearQueueImplmentation();
                break;

            case 10: linearQueue.linearQueueElements();
                LinearQueueImplmentation();
                break;

            case 11: linearQueue.destructor();
                rl.close();
                break;

            default: console.log("ERROR: Unknown");
                LinearQueueImplmentation();
                break;
        }
    })
}
LinearQueueImplmentation();
