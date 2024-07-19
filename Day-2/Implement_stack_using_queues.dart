class MyStack {
  List<int>queue1=[];
  MyStack() {
    
  }
  
  void push(int x) {
       queue1.add(x);
       
       for(int i=0;i<queue1.length-1;i++)
       {
          queue1.add(queue1.removeAt(0));
       }
  }
  
  int pop() {
      return queue1.removeAt(0);
  }
  
  int top() {
    return queue1.first;
  }
  
  bool empty() {
    return queue1.isEmpty;
  }
}
