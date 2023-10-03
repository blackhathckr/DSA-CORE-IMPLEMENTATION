// DSA - Stack Core Implementation
using System;
namespace Stack
{
    public class Stack
    {
        private int capacity;
        private int top;
        private int size;
        private readonly int[] stack;

        public Stack(int capacity)
        {
            this.capacity = capacity;
            top = -1;
            size = 0;
            stack = new int[capacity];
            Console.WriteLine("Stack of Capacity " + capacity + " Initialized");
        }

        public bool IsOverflow()
        {
            if (size > capacity - 1)
            {
                Console.WriteLine("Stack Overflow");
                return true;
            }
            else
            {
                Console.WriteLine("No Stack Overflow");
                return false;
            }
        }

        public bool IsUnderflow()
        {
            if (top == -1)
            {
                Console.WriteLine("Stack Underflow");
                return true;
            }
            else
            {
                Console.WriteLine("No Stack Underflow");
                return false;
            }
        }

        public void Push()
        {
            if (IsOverflow())
            {
                Console.WriteLine("Stack Overflow. Increase the Max Capacity of the Stack ");
            }
            else
            {
                string input;
                Console.WriteLine("Enter the Element to be Pushed into the Stack");
                input = Console.ReadLine();
                if (int.TryParse(input, out int ele))
                {
                    stack[++top] = ele;
                    size += 1;
                    Console.WriteLine("Element " + ele + " pushed into the Stack");
                }
            }
        }

        public void Pop()
        {
            if (IsUnderflow())
            {
                Console.WriteLine(" ");
            }
            else
            {
                int ele;
                ele = stack[top--];
                size -= 1;
                Console.WriteLine("Element " + ele + " Popped from the Stack");
            }
        }


        public void Peek()
        {
            if (IsUnderflow())
            {
                Console.WriteLine(" ");
            }
            else
            {
                Console.WriteLine("Peeked Element : " + stack[top]);
            }
        }

        public void ReverseStack()
        {
            if (IsUnderflow())
            {
                Console.WriteLine(" ");
            }
            else
            {
                int start = 0;
                int end = size - 1;
                while (start <= end)
                {
                    (stack[end], stack[start]) = (stack[start], stack[end]);
                    start++;
                    end--;
                }
                Console.WriteLine("Stack Reversed");
            }
        }

        public void SearchStack()
        {
            string input;
            int flag = 0;
            Console.WriteLine("Enter the Element to be Searched for in the Stack");
            input = Console.ReadLine();
            if (int.TryParse(input, out int ele))
            {
                for (int i = top; i >= 0; i--)
                {
                    if (ele == stack[i])
                    {
                        Console.WriteLine("Element " + ele + " Found in the Stack");
                        flag++;
                        break;
                    }
                }
            }
            if (flag == 0)
            {
                Console.WriteLine("Element " + ele + " Not Found in the Stack");
            }

        }

        public void StackElementsCount()
        {
            if (IsUnderflow())
            {
                Console.WriteLine(" ");
            }
            else
            {
                int count = 0;
                for (int i = top; i >= 0; i--)
                {
                    count++;
                }
                Console.WriteLine("Stack Elements Count : " + count);
            }
        }

        public void StackElements()
        {
            if (IsUnderflow())
            {
                Console.WriteLine(" ");
            }
            else
            {
                Console.WriteLine("Stack Elements :");
                for (int i = top; i >= 0; i--)
                {
                    Console.WriteLine(stack[i]);
                }
            }
        }

        public void IncreaseStackCapacity()
        {
            string newCap;
            Console.WriteLine("Enter the New Capacity of the Stack");
            newCap = Console.ReadLine();
            if (int.TryParse(newCap, out int newCapacity))
            {
                capacity = newCapacity;
                Console.WriteLine("New Max Capacity of Stack : " + capacity);
            }
        }

        public void ClearStack()
        {
            if (IsUnderflow())
            {
                Console.WriteLine(" ");
            }
            else
            {
                for (int i = top; i >= 0; i--)
                {
                    Pop();
                }
                Console.WriteLine("Stack Cleared ");
            }
        }


        ~Stack()
        {
            Console.WriteLine("Stack Destroyed by Destructor");
        }
    }

    class MainActivity
    {
        public static void Main(string[] args)
        {
            string cap;
            int capacity;
            Console.WriteLine("Enter the capacity of the Stack");
            cap = Console.ReadLine();
            capacity = int.Parse(cap);
            Stack s = new(capacity);
            Console.WriteLine("DSA - Stack Core Implementation in C# ( Csharp )");
            string input;
            int op;
            do
            {
                Console.WriteLine(" ");
                Console.WriteLine("Choose from the Following Options ");
                Console.WriteLine("1.isOverflow ");
                Console.WriteLine("2.isUnderFlow ");
                Console.WriteLine("3.Push ");
                Console.WriteLine("4.Pop ");
                Console.WriteLine("5.Peek ");
                Console.WriteLine("6.Reverse Stack");
                Console.WriteLine("7.Search Stack");
                Console.WriteLine("8.Stack Elements Count");
                Console.WriteLine("9.Stack Elements");
                Console.WriteLine("10.Increase Stack Capacity");
                Console.WriteLine("11.Clear Stack");
                Console.WriteLine("12.Exit");
                Console.WriteLine(" ");
                input = Console.ReadLine();
                op = int.Parse(input);
                //Console.WriteLine(" ");
                switch (op)
                {
                    case 1:
                        s.IsOverflow();
                        break;

                    case 2:
                        s.IsUnderflow();
                        break;

                    case 3:
                        s.Push();
                        break;

                    case 4:
                        s.Pop();
                        break;

                    case 5:
                        s.Peek();
                        break;

                    case 6:
                        s.ReverseStack();
                        break;

                    case 7:
                        s.SearchStack();
                        break;

                    case 8:
                        s.StackElementsCount();
                        break;

                    case 9:
                        s.StackElements();
                        break;

                    case 10:
                        s.IncreaseStackCapacity();
                        break;

                    case 11:
                        s.ClearStack();
                        break;

                    case 12:
                        break;

                    default:
                        Console.WriteLine("Invalid Option");
                        break;
                }
            } while (op != 12);
        }
    }
}

