#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>



template <typename T>
class Node{
	public:
		T data;
		Node* next;
		
		Node(T new_data){
			data = new_data;
			next = nullptr;
		}
	
	
};
template <typename T>
class Queue{
	private:
		Node<T> *front;
		Node<T> *rear;
	public:
		//creates an empty queue
		Queue(){
			front = rear = nullptr;
			std::cout<<"A queue has been created.\n";
		}		
		
		//isEmpty
		bool isEmpty(){
			return front == nullptr;
		}
		
		//enqueue
		void enqueue(T new_data){
			Node<T> *new_node=new Node<T> (new_data);
			if (isEmpty()){
				front = rear = new_node;
				std::cout<<"Equeued to an empty queue.\n";
				return;
			}
			rear->next=new_node;
			rear=new_node; 
			std::cout<<"Successfully enqueued.\n";
		}
		
		//dequeue
		void dequeue(){
			if (isEmpty()){
				return;	
			}
			
			Node<T>* temp=front;
			
			if (front==nullptr) {
			rear=nullptr;
			}
			else{
				front=front->next; 
			}
			delete temp;
		}
		
		//getfront
		void getFront(){
			if (isEmpty()){
				std::cout<<"The queue is empty.\n";
				return;
			}
			std::cout<<"Current Front: "<<front->data<<std::endl;
		}
		
		//getrear
		void getRear(){
			if (isEmpty()){
				std::cout<<"The queue is empty.\n";
				return;
			}
			std::cout<<"Current Rear: "<<rear->data<<std::endl;
		}
		
		//display
		void display(){
			if (isEmpty()){
				std::cout<<"The queue is empty.\n";
				return;
			}
			Node<T> *temp=front;
			while (temp!=nullptr){
				std::cout<<temp->data<<" ";
				temp=temp->next;
			}
			std::cout<<std::endl;
		}
		
		//to deallocate memory
		~Queue(){
			while(!isEmpty()){
				dequeue();
			}
		}
		
};

#endif
