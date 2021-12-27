// RiderList.h: Declare a class to represent a list of 
//              motorcycle grand prix riders.
//
// Name: Christa Manges
// Course Number/Section: CS 221-02
// Date: 4/09/2021

#ifndef RIDER_LIST_H
#define RIDER_LIST_H

#include "MotoGpRider.h"

// A node containing a MotoGpRider and the address to the next node.
struct NodeType; 

class RiderList
{
public:
	// Default constructor that initializes the number of riders to 0.
	RiderList();

	// Class destructor that deletes dynamically allocated memory.
	~RiderList();

	// The MotoGPRider that is passed in as a parameter is
	// added to the list.  
	// As a precondition, the list must not already be full.
	void AddRider(MotoGpRider rider);

	// Reset the current position to go back to the start of the list.
	void Reset();

	// Check to see if the list of riders has a rider at the current
	// position in the list.
	bool HasNext() const;

	// Gets the rider at the current position of the list of riders
	// and moves the current position up one space.  If the current 
	// position is at the end of the list, the current position loops
	// back around to the beginning of the list. As a precondition, 
	// the list must have at least one element.
	MotoGpRider GetNext();

	// Clear out the list to make it empty.
	void ClearList();

	// Test if the list is full.
	bool IsFull() const;

	// Get the size of the list.
	int GetSize() const;

private:
	NodeType* riderData;   // The node of the first rider in the list.
	int size;              // The number of riders in the list.
	NodeType* currentPos;  // The current position in the list.
	bool start;            // True if the current position is before the
	                       // start of the list, it is the first time
						   // looping through the list without resetting
						   // it, and the list containst at least one
						   // element before being reset.

};



#endif