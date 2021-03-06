/********************************************************************

I declare that the following program was written by me and that I have NOT copied any part of this code from any other source.

Name: Mieabiye C Selema

Email: sc17ms@leeds.ac.uk

Date: 20/11/2017

*********************************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#define MAX 59
#define rooms 10

int queue[MAX] = { 0 };
int Doc[rooms] = { 0 };
int first = -1, last = -1;
int room, option, value, n, DoctorPassword, i, location, found;
char choice;

//Patient Commands
bool IsEmpty()
{
	if (first == -1 && last == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}// Checks if the queue is empty

bool IsFull()
{
	if ((last + 1) % MAX == first)
	{
		return true;
	}
	else
	{
		return false;
	}
}//Checks if the queue is full

bool InQueue()
{
	bool IQ = false;
	for (int i = 0; i < MAX; i++)
	{
		if (n == queue[i])
		{
			return true;
			IQ = true;
		}
	}

	if (IQ == false)
	{
		return false;
	}
}// Checks if the n is already in the queue

bool password()
{
	printf("To access this command. Password is required: ");
	scanf("%i", &DoctorPassword);

	if (DoctorPassword == 1234)
	{
		return true;
	}
	else
	{
		printf("Sorry, you have entered the wrong password.\n");
		return false;
	}
}// Password is needed to run most of staff commands

void Clear()
{
	int i = 0;

	for (i; i <= MAX; i++)
	{
		queue[i] = 0;
		first = -1;
		last = -1;
	}
}

void enqueue(int n)
{
	if (last == MAX)
	{
		printf("The queue is full\n");
	}
	else
	{
		if (InQueue() == true)
		{
			printf("You're already checked in\n");
			PositionInWaiting(n);
		}
		else
		{
			if (first == -1)
			{
				first = 0;
			}
			last++;
			queue[last] = n;
			printf("Welcome Patient No. %i\n", n);
			printf("There are no doctors available at the Moment. Please relax in the waiting area\n");
		}
	}
}//Enqueue's the patient to the line

void Remove(int n, int found)
{
	for (i = 0; i <= MAX; i++)
	{
		if (n == queue[i])
		{
			found = 1;
			location = i;
		}
	}
	if (found == 1)
	{
		for (i = location; i <= MAX; i++)
		{
			queue[i] = queue[i + 1];
		}
		printf("You have been removed from the queue!\nThank you for your visit \n");
		last--;
	}
	else
	{
		printf("You're not in the queue\n");
	}
}

void AvailableDoctors()
{
	for (i = 0; i <= rooms; i++)
	{
		if (Doc[i] == 1)
		{
			int roomno = i + 1;
			printf("Doctor %i is avaliable\n", roomno);
		}
	}
}

int PositionInWaiting(int n)
{
	bool Ptrue = false;
	int i = 0;
	for (i; i <= MAX; i++)
	{
		if (n == queue[i])
		{
			location = i + 1;
			printf("You are in position %i in the queue\n", location);
			Ptrue = true;
		}
	}

	if (Ptrue == false)
	{
		printf("You are not in the queue\n");
	}

}

//Staff Commands 
void ready(int room, int n)// It sends the right patient to the right room, but I dont know how to make it display to the user. so if you enter in a patient and then press r 1, it will send the right patient but it outputs to the user that it sent patient 0
{
	int element;

	element = room - 1;

	Doc[element] = 1;
	int i = 0;
	for (i; i <= rooms; i++)
	{
		int element = room - 1;
		if (Doc[element] == 1)
		{
			Doc[element] = n;
			dequeue(n);
			printf("Patient %i, Please Go To Room %i.\n", n, room);
			printf(" %i\n", Doc[element]);
			break;
		}

	}

}

void away()
{
	int element;

	element = room - 1;

	Doc[element] = 0;
} // This function tells the user the doctor is away from his room

void WaitingLine()
{
	printf("Patients waiting are:\n");
	for (i = 0; i < MAX; i++)
	{
		if (queue[i] != 0) //checks they have real ID numbers not just 0
		{
			printf("%d, ", queue[i]);
		}
	}
	printf("\n");
} //This function shows who is waiting in the line

int dequeue()
{
	int temp = queue[first];

	if (first == last)
	{
		Clear();
	}
	else if (!IsEmpty())
	{
		queue[first] = 0;
		first++;

		if (first == MAX)
		{
			first = 0;
		}
	}

	return temp;
} //removes a patient from the queue

int main()
{
	printf("System is ready. Enter your command\n");

	while (1) //This while loop will not stop running until the program is exited
	{
		n = 0;
		printf(">>>"); 
		scanf(" %c", &choice);

		switch (choice) 
		{
		case 'i':
			scanf("%i", &n);
			enqueue(n);
			break;
		case 'p':
			scanf(" %i", &n);
			PositionInWaiting(n);
			break;
		case 'q':
			scanf(" %i", &n);
			Remove(n, found);
			break;
		case 'h':
			printf("Press i to join the queue.\n");
			printf("Press p to know your position in the queue.\n");
			printf("Press q to exit the queue.\n");
			printf("Press d to display the avaliable doctors.\n");
			break;
		case 'x':
			if (password() == true) //The user will need a password to access staff commands
				exit(1);
			break;
		case 'w':
			if (password() == true)
				WaitingLine();
			break;
		case 'd':
			AvailableDoctors();
			break;
		case 'o':
			scanf(" %i", &n);
			if (password() == true)
			{
				dequeue(n);
			}
			break;
		case 'r':
			scanf(" %i", &room);
			ready(room, n);
			break;
		case 'a':
			scanf(" %i", &room);
			away(room);
			break;
		default:
			printf("That is not an option\n");
		}
	}

	return 0;
}// This is the main function where all other functions are run.




