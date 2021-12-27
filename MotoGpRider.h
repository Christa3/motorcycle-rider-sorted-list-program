// MotoGpRider.h: Declare a class to represent a motorcycle grand prix rider.
//
// Name: Christa Manges
// Course Number/Section: CS 221-02
// Date: 4/09/2021


#ifndef MOTO_GP_RIDER_H
#define MOTO_GP_RIDER_H

#include <string>

// An enumerated class describing relations
// between items.
enum class RelationType { LESS, GREATER, EQUAL };

class MotoGpRider
{
public:

	// Construct a new MotoGpRider, setting the last name,
	// first name, racing number, nation, motorcycle make,
	// world championship points, and world championship
	// position.
	MotoGpRider(std::string newLastName, std::string newFirstName,
		int newRacingNum, std::string newNation, std::string newMotorcycle,
		int newPoints, int newPosition);

	// Default constructor that sets the last name, first name,
	// nation, and motorcycle make to "unknown" and the racing
	// number, world championship points, and world championship
	// position to 0.
	MotoGpRider();

	// Return the rider's number.
	int GetRacingNum() const;

	// Return the make of the rider's motorcycle.
	std::string GetMotorcycle() const;

	// Return the nation that the rider comes from.
	std::string GetNation() const;

	// Return the world championship position of the rider.
	int GetPosition() const;

	// Return the rider's full name, racing number, world championship points,
	// and world championship position as a string.
	std::string Summary() const;

	// Return the rider's full name (first name followed by last name).
	std::string FullName() const;

	// Returns LESS if calling rider has a lower racing number than
	// otherRider.  Returns GREATER if calling rider has a higher
	// racing number than otherRider.  Returns EQUAL if calling
	// rider has the same racing number as otherRider.
	RelationType ComparedTo(MotoGpRider otherRider) const;


private:
	std::string lastName;       // The rider's last name.
	std::string firstName;      // The rider's first name.
	int racingNum;              // The rider's racing number.
	std::string nation;         // The nation the rider is from.
	std::string motorcycle;     // The make of the rider's motorcycle.
	int points;                 // The rider's world championship points.
	int position;               // The rider's world championship position.
};

#endif
