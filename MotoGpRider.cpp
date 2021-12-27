// MotoGpRider.cpp: Provide implementation of member functions of 
// class MotoGPRider.
//
// Name: Christa Manges
// Course Number/Section: CS 221-02
// Date: 4/09/2021 

#include <sstream>
#include <iostream>
#include <iomanip>

#include "MotoGpRider.h"

// Construct a new MotoGpRider, setting the last name,
// first name, racing number, nation, motorcycle make,
// world championship points, and world championship
// position.
MotoGpRider::MotoGpRider(std::string newLastName, std::string newFirstName,
	int newRacingNum, std::string newNation, std::string newMotorcycle,
	int newPoints, int newPosition)
	: lastName{ newLastName }, firstName{ newFirstName },
	racingNum{ newRacingNum }, nation{ newNation },
	motorcycle{ newMotorcycle }, points{ newPoints },
	position{ newPosition }
{

}

// Default constructor that sets the last name and first name,
// to "unknown", the racing number to 0, the nation to "unknown",
// and the world champtionship points and world champtionship
// postion to 0.
MotoGpRider::MotoGpRider()
	: lastName{ "unknown" }, firstName{ "unknown" },
	racingNum{ 0 }, nation{ "unknown" },
	motorcycle{ "unknown" }, points{ 0 },
	position{ 0 }
{

}


// Return the rider's number.
int MotoGpRider::GetRacingNum() const
{
	return racingNum;
}

// Return the make of the rider's motorcycle.
std::string MotoGpRider::GetMotorcycle() const
{
	return motorcycle;
}

// Return the nation that the rider comes from.
std::string MotoGpRider::GetNation() const
{
	return nation;
}

// Return the world championship position of the rider.
int MotoGpRider::GetPosition() const
{
	return position;
}

// Return the rider's full name, racing number, world championship points,
// and world championship position as a string.
std::string MotoGpRider::Summary() const
{
	std::stringstream RiderInfo; // The summary of the rider.
	std::string name = FullName(); // The rider's full name.

	RiderInfo << std::setw(19) << name << " :" << std::setw(6)
		<< racingNum << std::setw(9) << points << std::setw(10) << position;

	return RiderInfo.str();
}

// Return the rider's full name (first name followed by last name).
std::string MotoGpRider::FullName() const
{
	std::stringstream Name; // The full name of the rider.

	Name << firstName << " " << lastName;

	return Name.str();
}

// Returns LESS if calling rider has a lower racing number than
// otherRider.  Returns GREATER if calling rider has a higher
// racing number than otherRider.  Returns EQUAL if calling
// rider has the same racing number as otherRider.
RelationType MotoGpRider::ComparedTo(MotoGpRider otherRider) const
{
	int riderNum = racingNum; // The racing number of the calling rider.
	int otherRiderNum = otherRider.GetRacingNum(); // The racing number of 
	                                               // otherRider.

	// Test which racing number is larger and return appropriate
	// RelationType
	if (riderNum < otherRiderNum)
		return RelationType::LESS;
	else if (riderNum > otherRiderNum)
		return RelationType::GREATER;
	else // racing numbers are equal
		return RelationType::EQUAL;
}