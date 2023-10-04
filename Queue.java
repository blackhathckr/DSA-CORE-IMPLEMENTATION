// DSA - Queue Core Implementation

import java.util.Scanner;

class Q {
    int front, rear, size, capacity;
    int[] queue;
    Scanner s = new Scanner(System.in);

    public Q(int capacity) {
        this.front = 0;
        this.capacity = capacity;
        this.rear = capacity - 1;
        this.size = 0;
        queue = new int[capacity];
        System.out.println("Queue of the Capacity: " + capacity + " Initialized");
    }

    boolean isFull() {
        if (size >= capacity - 1) {
            System.out.println("Queue is Full");
            return true;
        } else {
            System.out.println("Queue is Not Full");
            return false;
        }
    }

    boolean isEmpty() {
        if (size == 0) {
            System.out.println("Queue is Empty");
            return true;
        } else {
            System.out.println("Queue is Not Empty");
            return false;
        }
    }

    void enqueue() {
        if (isFull()) {
            System.out.println("Enqueue Not Possible. Queue is Full. Increase the Queue Max Capacity ");
        } else {
            int ele;
            System.out.println("Enter the Element to enqueue");
            ele = s.nextInt();
            rear = (rear + 1) % capacity;
            queue[rear] = ele;
            size += 1;
            System.out.println("Element " + ele + " enqueued");
        }
    }

    void dequeue() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            int ele;
            ele = queue[front];
            front = (front + 1) % capacity;
            size -= 1;
            System.out.println("Element " + ele + " dequeued");
        }
    }

    void queueFront() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            System.out.println("Queue Front : " + front);
        }
    }

    void reverseQueue() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            int start = front;
            int end = size - 1;
            while (start <= end) {
                int temp = queue[start];
                queue[start] = queue[end];
                queue[end] = temp;
                start++;
                end--;
            }
            System.out.println("Queue Reversed");
        }
    }

    void searchQueue() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            int ele, flag = 0;
            System.out.println("Enter the Element to Search for in the Queue");
            ele = s.nextInt();
            for (int i = front; i <= rear; i++) {
                if (ele == queue[i]) {
                    System.out.println("Element " + ele + " Found in the Queue");
                    flag++;
                    break;
                }
            }
            if (flag == 0) {
                System.out.println("Element " + ele + " Not Found in the Queue");
            }
        }
    }

    void queueElementsCount() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            int count = 0;
            for (int i = front; i <= rear; i++) {
                count++;
            }
            System.out.println("Queue Elements Count : " + count);
        }
    }

    void queueElements() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            System.out.println("Queue Elements :");
            for (int i = front; i <= rear; i++) {
                System.out.println(queue[i]);
            }
        }
    }

    void increaseQueueCapacity() {
        int newCapacity;
        System.out.println("Enter the New Max Capacity of the Queue");
        newCapacity = s.nextInt();
        this.capacity = newCapacity;
        System.out.println("New Max Capacity of Queue : " + capacity);
    }

    void clearQueue() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            for (int i = front; i <= rear; i++) {
                dequeue();
            }
        }
    }

    protected void finalize() {
        System.out.println("Queue Destroyed by Destructor");
    }
}

class Queue {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int capacity;
        System.out.println("Enter the Max Capacity of the Queue");
        capacity = s.nextInt();
        Q q = new Q(capacity);
        System.out.println("DSA - Queue Core Implementation");
        int op;
        do {
            System.out.println(" ");
            System.out.println("Choose from the Following Options");
            System.out.println("1.isFull");
            System.out.println("2.isEmpty");
            System.out.println("3.Enqueue");
            System.out.println("4.Dequeue");
            System.out.println("5.Queue Front");
            System.out.println("6.Reverse Queue");
            System.out.println("7.Search Queue");
            System.out.println("8.Queue Elements Count");
            System.out.println("9.Queue Elements");
            System.out.println("10.Increase Queue Capacity");
            System.out.println("11.ClearQueue");
            System.out.println("12.Exit");
            System.out.println(" ");
            op = s.nextInt();
            System.out.println(" ");
            switch (op) {
                case 1:
                    q.isFull();
                    break;

                case 2:
                    q.isEmpty();
                    break;

                case 3:
                    q.enqueue();
                    break;

                case 4:
                    q.dequeue();
                    break;

                case 5:
                    q.queueFront();
                    break;

                case 6:
                    q.reverseQueue();
                    break;

                case 7:
                    q.searchQueue();
                    break;

                case 8:
                    q.queueElementsCount();
                    break;

                case 9:
                    q.queueElements();
                    break;

                case 10:
                    q.increaseQueueCapacity();
                    break;

                case 11:
                    q.clearQueue();
                    ;
                    break;

                case 12:
                    break;

                default:
                    System.out.println("Invalid Option");
                    break;
            }
        } while (op != 12);

    }
}