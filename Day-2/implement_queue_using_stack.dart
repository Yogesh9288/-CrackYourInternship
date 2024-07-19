class MyQueue {

  List<int>stack1=[];
  List<int>stack2=[];
  MyQueue() {
    
  }
  
  void push(int x) {
       while(!stack1.isEmpty)
       {
          stack2.add(stack1.removeLast());
       }
       stack1.add(x);
       while(!stack2.isEmpty)
       {
          stack1.add(stack2.removeLast());
       }
  }
  
  int pop() {
      return stack1.removeLast();
  }
  
  int peek() {
     return stack1.last;
  }
  
  bool empty() {
       return stack1.isEmpty;
  }
}
