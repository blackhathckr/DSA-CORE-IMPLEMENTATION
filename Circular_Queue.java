// DSA - Circular Queue Core Implementation

import java.util.Scanner;

class CQ {
    int front, rear, size, capacity;
    int[] queue;
    Scanner s = new Scanner(System.in);

    public CQ(int capacity) {
        this.front = 0;
        this.capacity = capacity;
        this.rear = capacity - 1;
        this.size = 0;
        queue = new int[capacity];
        System.out.println("Circular Queue of the Capacity: " + capacity + " Initialized");
    }

    boolean isFull() {
        if (size >= capacity - 1) {
            System.out.println("Circular Queue is Full");
            return true;
        } else {
            System.out.println("Circular Queue is Not Full");
            return false;
        }
    }

    boolean isEmpty() {
        if (size == 0) {
            System.out.println("Circular Queue is Empty");
            return true;
        } else {
            System.out.println("Circular Queue is Not Empty");
            return false;
        }
    }

    void enqueue() {
        if (isFull()) {
            System.out.println("Enqueue Not Possible. Circular Queue is Full. Increase the Circular Queue Max Capacity ");
        } else {
            int ele;
            System.out.println("Enter the Element to Enqueue");
            ele = s.nextInt();
            rear = (rear + 1) % capacity;
            queue[rear] = ele;
            size += 1;
            System.out.println("Element " + ele + " Enqueued");
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

    void circularQueueFront() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            System.out.println("Circular Queue Front : " + front);
        }
    }

    void reverseCircularQueue() {
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

    void searchCircularQueue() {
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

    void circularQueueElementsCount() {
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

    void circularQueueElements() {
        if (isEmpty()) {
            System.out.println(" ");
        } else {
            System.out.println("Queue Elements :");
            for (int i = front; i <= rear; i++) {
                System.out.println(queue[i]);
            }
        }
    }

    void increaseCircularQueueCapacity() {
        int newCapacity;
        System.out.println("Enter the New Max Capacity of the Queue");
        newCapacity = s.nextInt();
        this.capacity = newCapacity;
        System.out.println("New Max Capacity of Queue : " + capacity);
    }

    void clearCircularQueue() {
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

class Circular_Queue {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int capacity;
        System.out.println("Enter the Max Capacity of the Circular Queue");
        capacity = s.nextInt();
        CQ cq = new CQ(capacity);
        System.out.println("DSA - Circular Queue Core Implementation");
        int op;
        do {
            System.out.println(" ");
            System.out.println("Choose from the Following Options");
            System.out.println("1.isFull");
            System.out.println("2.isEmpty");
            System.out.println("3.Enqueue");
            System.out.println("4.Dequeue");
            System.out.println("5.Circular Queue Front");
            System.out.println("6.Reverse Circular Queue");
            System.out.println("7.Search Circular Queue");
            System.out.println("8.Circular Queue Elements Count");
            System.out.println("9.Circular Queue Elements");
            System.out.println("10.Increase Circular Queue Capacity");
            System.out.println("11.Clear Circular Queue");
            System.out.println("12.Exit");
            System.out.println(" ");
            op = s.nextInt();
            System.out.println(" ");
            switch (op) {
                case 1:
                    cq.isFull();
                    break;

                case 2:
                    cq.isEmpty();
                    break;

                case 3:
                    cq.enqueue();
                    break;

                case 4:
                    cq.dequeue();
                    break;

                case 5:
                    cq.circularQueueFront();
                    break;

                case 6:
                    cq.reverseCircularQueue();
                    break;

                case 7:
                    cq.searchCircularQueue();
                    break;

                case 8:
                    cq.circularQueueElementsCount();
                    break;

                case 9:
                    cq.circularQueueElements();
                    break;

                case 10:
                    cq.increaseCircularQueueCapacity();
                    break;

                case 11:
                    cq.clearCircularQueue();
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