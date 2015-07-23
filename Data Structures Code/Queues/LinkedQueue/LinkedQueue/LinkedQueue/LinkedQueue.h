#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template <class NodeType>
struct QueueNode
{
	NodeType data;
	QueueNode *nextNodePtr;
};

template <class NodeType>
class LinkedQueue
{
public:
	LinkedQueue();
	bool isQueueEmpty();
	bool peekAtQueueFront( NodeType & );
	bool peekAtQueueRear( NodeType & );
	bool enQueue( const NodeType & );
	bool deQueue( NodeType & );
	void resetQueue();
	void printQueue();
	void getQueueSize( int & );
	~LinkedQueue( );

private: 
	QueueNode<NodeType> * queueFront;
	QueueNode<NodeType> * queueRear;
	int queueSize;
	QueueNode<NodeType> * createNewNode( const NodeType & );
}; 

template <class NodeType>
LinkedQueue<NodeType>::LinkedQueue()
{
	queueFront = NULL;
	queueRear  = NULL;
	queueSize  = 0;
}

template <class NodeType>
LinkedQueue<NodeType>::~LinkedQueue()
{
	if( !isQueueEmpty())
	{
		QueueNode<NodeType>* temp;
		while( queueFront != NULL)
		{
			temp = queueFront;
			queueFront = queueFront -> nextNodePtr;
			delete temp;
		}
	}
}

template <class NodeType>
void LinkedQueue<NodeType>::resetQueue()
{
	if( !isQueueEmpty())
	{
		QueueNode<NodeType>* temp;
		while( queueFront != NULL)
		{
			temp = queueFront;
			queueFront = queueFront -> nextNodePtr;
			delete temp;
		}

		queueFront = NULL;
		queueRear  = NULL;
		queueSize  = 0;
	}

	return;
}

template <class NodeType>
bool LinkedQueue<NodeType>::isQueueEmpty()
{
	return (queueFront == NULL);
}

template <class NodeType>
bool LinkedQueue<NodeType>::peekAtQueueFront( NodeType & item)
{
	if( !isQueueEmpty())
	{
		item = queueFront -> data;
		return true;
	}
	else
	{
		cerr << "Queue is empty. Cannot peek at the front of an empty queue." << endl;
		return false;
	}
}

template <class NodeType>
bool LinkedQueue<NodeType>::peekAtQueueRear( NodeType & item)
{
	if( !isQueueEmpty())
	{
		item = queueRear -> data;
		return true;
	}
	else
	{
		cerr << "Queue is empty. Cannot peek at the rear of an empty queue." << endl;
		return false;
	}
}

template <class NodeType>
QueueNode<NodeType>* LinkedQueue<NodeType>::createNewNode( const NodeType & value)
{
	QueueNode<NodeType>* temp = new (QueueNode<NodeType>);

	assert( temp);
	temp -> data = value;
	temp -> nextNodePtr = NULL;
	return temp;
}

template <class NodeType>
bool LinkedQueue<NodeType>::enQueue( const NodeType & newItem)
{
	if( isQueueEmpty())
	{
		queueRear = createNewNode( newItem);
		queueFront = queueRear;
		queueSize++;
		return true;
	}

	QueueNode<NodeType> * temp = createNewNode( newItem);
	queueRear -> nextNodePtr = temp;
	queueRear = temp;
	queueSize++;
	return true;
}

template <class NodeType>
bool LinkedQueue<NodeType>::deQueue( NodeType & item)
{
	if( isQueueEmpty())
	{
		cerr << "Queue is empty. Cannot retrieve from an empty queue." << endl;
		return false;
	}

	QueueNode<NodeType> * temp = queueFront;
	item = queueFront -> data;
	queueFront = queueFront -> nextNodePtr;
	queueSize--;
	delete temp;

	return true;
}

template <class NodeType>
void LinkedQueue<NodeType>::printQueue()
{
	if( isQueueEmpty())
	{
		cout << "Queue is empty. Cannot print an empty queue." << endl;
		return;
	}

	QueueNode<NodeType>* temp = queueFront;
	while( temp != NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> nextNodePtr;
	}
	
	return;
}

template <class NodeType>
void LinkedQueue<NodeType>::getQueueSize( int & size)
{
	int size = queueSize;
	return;
}

#endif;