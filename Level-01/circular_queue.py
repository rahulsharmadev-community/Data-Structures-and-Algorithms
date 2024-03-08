
class CircularQueue:
    def __init__(self, MAX:int):
        self.queue=[None]*MAX
        self.MAX= MAX
        self.f=self.r=-1
        pass
    

    def enQueue(self,element:int):
        """
        Adds an element to the circular queue.

        Parameters:
        - element (int): Element to be added to the queue.
        """
        if((self.f==0 & self.r == self.MAX-1) | (self.r+1)%self.MAX == self.f):
            return;
        
        if(self.f==-1 & self.r == -1):
            self.f=self.r=0
        else:
            self.r=(self.r+1) % self.MAX
            
        self.queue[self.r]=element
        
    def deQueue(self):
        """Removes an element from the circular queue."""
        
        if(self.f==-1 & self.r == -1):
            return;
        
        self.f=(self.f+1) % self.MAX
        
        if((self.r+1)%self.MAX == self.f): 
            self.f=self.r=-1
            
    def  display(self):
        """Function for display elements and status(f,r) of the circular queue."""
        
        if(self.f==-1 & self.r==-1):
            print("\n----Queue is empty----")
        else:
            print(f"\nFront = {self.f}, Rear = {self.r}");
            print("Elements:", end =" ")
            
            i=self.f
            while True:
                print(self.queue[i],end =", ")
                if(i==self.r): break
                
                # Increment index in a circular manner
                i=(i+1)%self.MAX
                
            if((self.f==0 & self.r == self.MAX-1)| (self.r+1)%self.MAX == self.f):
                print("<----Queue is full")
        print("\n")
        return;


# Program start form here 
def  main():
    queue= CircularQueue(5)
    while(1):
        print("\n(1. EnQueue, 2. DeQueue, 0. Exit.)")
        inp=input("Choose an option: ")
        if(inp=="1"):
            n = input("Enter an element: ")
            queue.enQueue(int(n))
        elif(inp=="2"): 
            queue.deQueue()
        elif(inp=="0"): break
        queue.display()
        
    

if __name__ == "__main__":
    main()
    


