#include <iostream>

double getTotal(double notes[], int notesSize);

int main()
{

	double notes[]{65, 25, 100, 96, 85, 73};
	int notesSize = sizeof(notes) / sizeof(notes[0]);
	double notesTotal = getTotal(notes, notesSize);

	std::cout << notesTotal / notesSize << " GPA\n";

	return 0;
}

double getTotal(double notes[], int notesSize)
{
	double notesTotal{};

	for (int i{0}; i < notesSize; i++)
	{
		notesTotal += notes[i];
	}

	return notesTotal;
}