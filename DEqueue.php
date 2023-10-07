<?php 
class DEqueue 
{
    public $capacity,$size,$front,$rear,$DEqueue;
    public function __construct($capacity)
    {
        $this->capacity = $capacity;
        $this->size=0;
        $this->front=-1;
        $this->rear=0;
        $this->DEqueue=array();
        echo "DEqueue of MAX Capacity : ".$this->capacity." Initialized \n";
    }

    public function isFull()
    {
        if($this->front==0 && $this->rear==$this->capacity-1) 
        {
            echo "DEqueue is Full \n";
            return true;
        }
        else 
        {
            echo "DEqueue is Not Full \n";
            return false;
        }
    }

    public function isEmpty()
    {
        if($this->front==-1) 
        {
            echo "DEqueue is Empty \n";
            return true;
        }
        else 
        {
            echo "DEqueue is Not Empty \n";
            return false;
        }
    }

    public function getFront()
    {
        if($this->isEmpty())
        {
            echo "\n";
        }
        else 
        {
            echo "DEqueue Front : ".$this->front."\n";
        }
    }

    public function getRear()
    {
        if($this->isEmpty())
        {
            echo "\n";
        }
        else 
        {
            echo "DEqueue Rear : ".$this->rear."\n";
        }
    }

    public function pushFront()
    {
        if($this->isFull())
        {
            echo "\n";
        }
        else 
        {
            if($this->front==-1)
            {
                $this->front=$this->rear=0;
            }
            else if($this->front==0)
            {
                $this->front=$this->capacity-1;
            }
            else 
            {
                $this->front--;
            }
        }
        echo "Enter the Element to Push at the Front of the DEueue \n";
        $ele=fgets(STDIN);
        $ele=rtrim($ele);
        $this->DEqueue[$this->front]=$ele;
        $this->size++;
        echo "Element ".$ele." Pushed at the Front of the DEqueue \n";
        
    }

    public function popFront()
    {
        if($this->isEmpty())
        {
            echo "\n";
        }
        else 
        {
            if($this->front==$this->rear)
            {
                $this->front=$this->rear=-1;
                $this->size--;
            }
            else if($this->front==$this->capacity-1)
            {
                $this->front=0;
                $this->size--;
            }   
            else 
            {
                $ele=$this->DEqueue[$this->front];
                echo "Element ".$ele." Popped from the Front of the DEqueue \n"; 
                $this->front++;
                $this->size--;
            }
        }
    }

    public function pushRear()
    {
        if($this->isFull())
        {
            echo "\n";
        }
        else 
        {
            if($this->front==-1)
            {
                $this->front=$this->rear=0;
            }
            else if($this->rear==$this->capacity-1)
            {
                $this->rear=0;
            }
            else 
            {
                $this->rear++;
            }
        }
        echo "Enter the Element to Push at the Rear of the DEqueue \n";
        $ele=fgets(STDIN);
        $ele=rtrim($ele);
        $this->DEqueue[$this->rear]=$ele;
        $this->size++;
        echo "Element ".$ele." Pushed at the Rear of the DEqueue \n";
    }

    public function popRear()
    {
        if($this->isEmpty())
        {
            echo "\n";
        }
        else
        {
            if($this->front==$this->rear)
            {
                echo "Element : ".$this->DEqueue[$this->rear]." Popped from the Rear of the DEqueue \n";
                $this->front=$this->rear=-1;
                $this->size--;
            }
            else if($this->rear==0)
            {
                echo "Element : ".$this->DEqueue[$this->rear]." Popped from the Rear of the DEqueue \n";
                $this->rear=$this->capacity-1;
                $this->size--;
            }
            else 
            {
                echo "Element : ".$this->DEqueue[$this->rear]." Popped from the Rear of the DEqueue \n";
                $this->rear--;
                $this->size--;
            }
            
        }
    }

    public function searchDEqueue()
    {
        if($this->isEmpty())
        {
            echo "\n";
        }
        else 
        {
            echo "Enter the Element to Search for in the DEqueue \n";
            $ele=fgets(STDIN);
            $ele=rtrim($ele);
            $curr=$this->front;
            $flag=0;
            while(true)
            {
                if($ele==$this->DEqueue[$curr])
                {
                    echo "Element ".$ele." Found in the DEqueue \n";
                    $flag++;
                    break;
                }
                if($curr==$this->rear)
                {
                    break;
                }
                $curr=($curr+1)%$this->capacity;
            }
            if($flag==0)
            {
                echo "Element ".$ele." Not found in the DEqueue \n";
            }
        }
    }

    public function DEqueueElementsCount()
    {
        if($this->isEmpty())
        {
            echo "\n";
        }
        else 
        {
            echo "DEqueue Elements Count : ".$this->size."\n";
        }
    }

    public function DEqueueElements()
    {
        if($this->isEmpty())
        {
            echo "\n";
        }
        else
        {
            $curr=$this->front;
            echo "DEqueue Elements : \n";
            while(true)
            {
                echo $this->DEqueue[$curr]."\n";
                if($curr==$this->rear)
                {
                    break;
                }
                $curr=($curr+1)%$this->capacity;
            }
            echo "\n";
        }
    }

    public function __destruct()
    {
        echo "DEqueue Destroyed by Destructor \n";
    }

}
echo "\n";
echo "DSA - DEqueue Core Implementation \n";
echo "Enter the MAX Capacity of the DEqueue \n";
$capacity=fgets(STDIN);
$capacity=rtrim($capacity);
$DEqueue=new DEqueue($capacity);
echo "\n";
do {
    echo "\n";
    echo "Choose from the Following Elements : \n";
    echo "1.isFull \n";
    echo "2.isEmpty \n";
    echo "3.Get Front \n";
    echo "4.Get Rear \n";
    echo "5.Push Front  \n";
    echo "6.Pop Front \n";
    echo "7.Push Rear \n";
    echo "8.Pop Rear \n";
    echo "9.Search DEqueue \n";
    echo "10.DEqueue Elements Count \n";
    echo "11.DEqueue Elements  \n";
    echo "12.Exit \n";
    echo "\n";
    $op=fgets(STDIN);
    $op=rtrim($op);
    switch ($op) {
        case 1:
            $DEqueue->isFull();
            break;

        case 2:
            $DEqueue->isEmpty();
            break;

        case 3:
            $DEqueue->getFront();
            break;
    
        case 4:
            $DEqueue->getRear();
            break;

        case 5:
            $DEqueue->pushFront();
            break;
    
        case 6:
            $DEqueue->popFront();
            break;
    
        case 7:
            $DEqueue->pushRear();
            break;
        
        case 8:
            $DEqueue->popRear();
            break;

        case 9:
            $DEqueue->searchDEqueue();
            break;

        case 10:
            $DEqueue->DEqueueElementsCount();
            break;
        
        case 11:
            $DEqueue->DEqueueElements();
            break;

        case 12:
            break;

        default:
            echo "Error Unknown \n";
            break;
    }
} while ($op!=12);
