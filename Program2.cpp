// Program2.cpp: Read in Motorcycle Grand Prix Rider information
// from a user-given input file.  Then print in a user-given output
// file a summary chart of rider information and below the chart, 
// print information about each rider.  Riders are storted in 
// ascending order by racing number.
//
// Name: Christa Manges
// Course Number/Section: CS 221-02
// Date: 4/09/2021

#include "MotoGpRider.h"
#include "RiderList.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int main()
{
	// Prompt the user for input and output file names.

	std::string inFileName, outFileName; // Names of the input and output files.

	std::cout << "Enter input file: ";
	std::cin >> inFileName;
	std::cout << "Enter output file: ";
	std::cin >> outFileName;

	// Open input file.
	std::fstream inData{ inFileName, std::ios_base::in };
	while (!inData)
	{
		std::cout << "Input file not found." << std::endl;
		std::cout << "Enter input file: ";
		std::cin >> inFileName;
		inData.close();
		inData.open(inFileName);
	}

	// Declare list of riders
	RiderList list;

	// Read each rider's information and add the rider to the list structure.
	// If the list is full, new riders are not added and a message saying
	// that the list is full will be printed for each rider after the
	// list is full.


	while (!inData.eof())
	{
		std::string lastName, firstName;
		int racingNum;
		std::string nation;
		std::string motorcycle;
		int points;
		int position;

		inData >> lastName >> firstName >> racingNum >> nation
			>> motorcycle >> points >> position;

		if (list.IsFull())
		{
			std::cout << "The rider list is full." << std::endl;
		}
		else
		{
			MotoGpRider rider{ lastName, firstName, racingNum,
			nation, motorcycle, points, position };
			list.AddRider(rider);
		}

	}


	// Close input file.
	inData.close();

	// Open output file.
	std::fstream outData(outFileName, std::ios_base::out);
	while (!outData)
	{
		std::cout << "Output file not found." << std::endl;
		std::cout << "Enter output file: ";
		std::cin >> outFileName;
		outData.close();
		outData.open(outFileName);
	}


	// Write a report summary to the output file, which contains a table
	// of World Championship statistics for each rider.

	// Print a title and headers for the table.
	outData << std::setw(45)
		<< "2018 World Championship Statistics" << std::endl << std::endl;
	outData << std::setw(14) << "RIDER NAME" << std::setw(15) << "NUMBER"
		<< std::setw(9) << "POINTS" << std::setw(11) << "POSITION"
		<< std::endl;
	outData << std::left << std::setfill('-') << std::setw(51) << " "
		<< std::endl;
	outData << std::right << std::setfill(' ');

	// Add a line to the table for each rider that contains the rider's full
	// name, their number, their World Championship points, and their World
	// Championship position.

	list.Reset();
	while (list.HasNext())
	{
		MotoGpRider rider = list.GetNext(); // Get the next rider.
		outData << rider.Summary() << std::endl;
	}

	// Write the details for each rider from the list into the output file.
	// Print out the full name, number, motorcylcle make, nation, and
	// world championship position each on a separate line.

	outData << std::endl << std::endl << "RIDERS" << std::endl;

	list.Reset();
	while (list.HasNext())
	{
		MotoGpRider rider = list.GetNext();
		outData << std::setfill('-') << std::setw(23) << "" << std::endl;
		outData << rider.FullName() << std::endl;
		outData << std::setw(23) << "" << std::endl;
		outData << std::left << std::setfill(' ');
		outData << std::setw(14) << "Number" << ": "
			<< rider.GetRacingNum() << std::endl;
		outData << std::setw(14) << "Motorcycle" << ": "
			<< rider.GetMotorcycle() << std::endl;
		outData << std::setw(14) << "Nation" << ": "
			<< rider.GetNation() << std::endl;
		outData << std::setw(14) << "Position" << ": "
			<< rider.GetPosition() << std::endl;
		outData << std::endl << std::right;
	}

	// Close output file.
	outData.close();

	// Clear list.
	list.ClearList();

	return 0;
}