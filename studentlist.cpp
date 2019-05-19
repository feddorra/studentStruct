#include <iostream>
#include <string.h>

using namespace std;

struct Student
{
	char surname[50];
	double score;
};

struct List
{
	Student data;
	List* next;
};

List* create_element(char surname[50], double score)
{
	List* element = new List;
	strcpy_s(element->data.surname, surname);
	element->data.score = score;
	element->next = NULL;

	return element;
}

void add_end(List** head, char surname[50], double score)
{
	if (*head == NULL)
	{
		*head = create_element(surname, score);
	}
	else
	{
		List* temp = *head;
		List* new_element = create_element(surname, score);

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_element;
	}
}

void add_start(List** head, char surname[50], double score)
{
	if (*head == NULL)
	{
		*head = create_element(surname, score);
	}
	else
	{
		List* new_element = create_element(surname, score);
		new_element->next = *head;
		*head = new_element;
	}
}

int length(List* head)
{
	if (head == NULL)
		return 0;
	else
	{
		List* temp = head;
		int len = 0;
		while (temp)
		{
			len++;
			temp = temp->next;
		}
		return len;
	}
}

void add_middle(List** head, char surname[50], double score)
{
	if (*head == NULL)
	{
		*head = create_element(surname, score);
	}
	else
	{
		List* new_element = create_element(surname, score);
		List* temp = *head;

		int len = length(temp);
		int mid = len / 2;
		int i = 1;

		while (i < mid)
		{
			temp = temp->next;
			i++;
		}
		new_element->next = temp->next;
		temp->next = new_element;
	}
}

void delete_end(List** head)
{
	if (*head == NULL)
	{
		cout << "Error: List is empty!" << endl;
	}
	else if ((*head)->next == NULL)
	{
		delete* head;
		*head = NULL;
	}
	else
	{
		List* temp = *head;

		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
}

void delete_start(List** head)
{
	if (*head == NULL)
	{
		cout << "Error: List is empty!" << endl;
	}
	else if ((*head)->next == NULL)
	{
		delete* head;
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
	}
}

void delete_middle(List** head)
{
	if (*head == NULL)
	{
		cout << "Error: List is empty!" << endl;
	}
	else if ((*head)->next == NULL)
	{
		delete* head;
		*head = NULL;
	}
	else
	{
		List* temp = *head;

		int len = length(temp);
		int mid = len / 2;
		int i = 1;

		while (i < mid)
		{
			temp = temp->next;
			i++;
		}
		temp->next = temp->next->next;
	}
}

void display(List* head)
{
	List* temp = head;
	while (temp)
	{
		cout << "Surname: " << temp->data.surname << ", score: " << temp->data.score << endl;
		temp = temp->next;
	}
}

void display_by_surname(List* head, char surname[50])
{
	List* temp = head;
	while (temp)
	{
		if(!strcmp(temp->data.surname, surname))
			cout << "Surname: " << temp->data.surname << ", score: " << temp->data.score << endl;
		temp = temp->next;
	}
}

void display_by_score(List* head, double score)
{
	List* temp = head;
	while (temp)
	{
		if (temp->data.score == score)
			cout << "Surname: " << temp->data.surname << ", score: " << temp->data.score << endl;
		temp = temp->next;
	}
}

enum Commands { ADD_END = 0, ADD_START, ADD_MIDDLE, DELETE_END, DELETE_START, DELETE_MIDDLE, LENGTH, DISPLAY, DISPLAY_BY_SURNAME, DISPLAY_BY_SCORE };

int main()
{
	char surname[50];
	double score;
	int command;
	int count;

	List* head = NULL;

	cout << "[COMMANDS]: ADD_END = 0, ADD_START = 1, ADD_MIDDLE = 2, DELETE_END = 3, DELETE_START = 4, DELETE_MIDDLE = 5, LENGTH = 6, DISPLAY = 7, DISPLAY_BY_SURNAME = 8, DISPLAY_BY_SCORE = 9";
	cout << endl;
	cout << "COMMAND: ";
	cin >> command;

	while (command != -666)
	{

		switch (command)
		{
		case ADD_END:
			cout << "Count of student: ";
			cin >> count;

			for (int i = 0; i < count; i++)
			{
				cout << "Surname: ";
				cin >> surname;
				cout << "Score: ";
				cin >> score;

				add_end(&head, surname, score);
			}
			break;

		case ADD_START:
			cout << "Count of student: ";
			cin >> count;

			for (int i = 0; i < count; i++)
			{
				cout << "Surname: ";
				cin >> surname;
				cout << "Score: ";
				cin >> score;

				add_start(&head, surname, score);
			}
			break;

		case ADD_MIDDLE:
			cout << "Count of student: ";
			cin >> count;

			for (int i = 0; i < count; i++)
			{
				cout << "Surname: ";
				cin >> surname;
				cout << "Score: ";
				cin >> score;

				add_middle(&head, surname, score);
			}
			break;

		case DELETE_START:
			cout << "Count of student: ";
			cin >> count;

			for (int i = 0; i < count; i++)
				delete_start(&head);
			break;

		case DELETE_END:
			cout << "Count of student: ";
			cin >> count;

			for (int i = 0; i < count; i++)
				delete_end(&head);
			break;

		case DELETE_MIDDLE:
			cout << "Count of student: ";
			cin >> count;

			for (int i = 0; i < count; i++)
				delete_middle(&head);
			break;

		case LENGTH:
			cout << "LIST LENGTH: " << length(head) << endl; 
			break;

		case DISPLAY:
			display(head);
			cout << endl;
			break;

		case DISPLAY_BY_SURNAME:
			cout << "Surname: ";
			cin >> surname;
			display_by_surname(head, surname);
			break;

		case DISPLAY_BY_SCORE:
			cout << "Score: ";
			cin >> score;
			display_by_score(head, score);
			break;

		default:
			break;
		}

		cout << "Command: ";
		cin >> command;
	}

	system("PAUSE");
	return 0;
}
