// RiderList.cpp: Provide implementation of member functions of class
// RiderList.
//
// Name: Christa Manges
// Course Number/Section: CS 221-02
// Date: 4/09/2021

#include "RiderList.h"
#include "MotoGpRider.h"

#include <string>
#include <new>

struct NodeType
{
	MotoGpRider info; // The MotoGpRider stored in the node.
	NodeType* next = nullptr; // A link to the next node in the list.
};

// Default constructor that initializes the number of riders to 0.
RiderList::RiderList()
	: riderData{ nullptr }, size {0}, currentPos{ nullptr }, start{ false }
	// start is false because the list does not contain at least one element
{

}


// The MotoGPRider that is passed in as a parameter is
// added to the list.  The rider is added in such a 
// way as to preserve the order of the riders.  If
// riders are equal in the ordering, the new rider
// is added to the list immediately after all riders
// it is equal to.
// As a precondition, the list must not already be full.
void RiderList::AddRider(MotoGpRider rider)
{
	NodeType* newNode;   // Pointer to node being inserted
	NodeType* predLoc;   // Trailing pointer
	NodeType* location;  // Traveling pointer
	bool moreToSearch;   // Determines if there is more of the list to search
	                     // to find the insertion point

	location = riderData;
	predLoc = nullptr;
	moreToSearch = (location != nullptr);
	// Find insertion point
	while (moreToSearch)
	{
		switch (rider.ComparedTo(location->info))
		{
			case RelationType::GREATER:
			case RelationType::EQUAL:   
				predLoc = location;
				location = location->next;
				moreToSearch = (location != nullptr);
				break;
			case RelationType::LESS:
				moreToSearch = false;
				break;

		}
	}

	// Prepare node for insertion
	newNode = new NodeType;
	newNode->info = rider;

	// Insert node into list.
	if (predLoc == nullptr)   // Insert as first.
	{
		newNode->next = riderData;
		riderData = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	size++;
}

// Reset the current position to go back to the start of the list.
void RiderList::Reset()
{
	currentPos = nullptr;
	if (size > 0) // Current postion is before the start of 
		          // the list with at least one element
		          // and it is the first time through the
		          // list without resetting it.
		start = true;
}

// Check to see if the list of riders has a rider at the current
// position in the list.
bool RiderList::HasNext() const
{
	// Return true if the current position is before the start of 
	// the list or the current node is not nullptr.
	// Return false if the current position is not before the start
	// of the list and the current node is nullptr (the end of the
	// list has been reached).
	return (start || currentPos);
}

// Gets the rider at the current position of the list of riders
// and moves the current position up one space.  If the current 
// position is at the end of the list, the current position loops
// back around to the beginning of the list. As a precondition, 
// the list must have at least one element.
MotoGpRider RiderList::GetNext()
{
	if (currentPos == nullptr)
	{
		// Executes if the current position is before
		// the beginning of the list or at the end of
		// the list.
		currentPos = riderData;
		start = false;
	}

	MotoGpRider rider = currentPos->info;
	currentPos = currentPos->next;
	return rider;
}

// Clear out the list to make it empty.
void RiderList::ClearList()
{
	NodeType* tempPtr;

	while (riderData)
	{
		tempPtr = riderData;
		riderData = riderData->next;
		delete tempPtr;
	}
}


// Test if the list is full.
bool RiderList::IsFull() const
{
	NodeType* location;
	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}


// Get the size of the list.
int RiderList::GetSize() const
{
	return size;
}

// Class destructor that deletes dynamically allocated memory.
RiderList::~RiderList()
{
	ClearList();
}

