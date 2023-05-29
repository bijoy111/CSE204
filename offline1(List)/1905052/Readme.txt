//There is an abstract class "List" in ADT.h header file whose  member functions are declared as pure virtual function. we use C++ template to support various types 
  of elements
//Arr.h header file contain a derived class "AList" that implements the "List" base class. In this class the list  allocate memory dynamically in chunk of x elements.
//LL.h header file contain a class "Link" for the node of the list. Every node has a value and a pointer to point the next node. The LL.h header file also contain 
  the derived class "LList" that implements the List base class.
//Main.cpp file import the header files ADT.h,Arr.h,LL.h. It takes input as described in question and give the update the list using the methods of Arr.h and LL.h files.
  It has print function to print the output.
//tnl.cpp file also import the header files ADT.h,Arr.h,LL.h. It takes input as described in question and print the list usign its print function. 
