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

void add_end(List** head, List *el)
{
	if (*head == NULL)
	{
		*head = el;
	}
	else
	{
		List* temp = *head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = el;
	}
}

void add_start(List** head, List* el)
{
	if (*head == NULL)
	{
		*head = el;
	}
	else
	{
		List* new_element = el;
		el->next = *head;
		*head = el;
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

List* search_by_surname(List* head, char surname[50])
{
	List* temp = head;
	while (temp->s)
	{
		if (!strcmp(temp->data.surname, surname))
			cout << "Surname: " << temp->data.surname << ", score: " << temp->data.score << endl;
		temp = temp->next;
	}
}

List* search_by_score(List* head, double score)
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

	List* head = NULL;

	List* el1 = create_element("FEDORENKO", 100);
	List* el2 = create_element("KONDRATUK", 100);

	add_end(&head, el1);
	add_start(&head, el2);

	display(head);
	

	system("PAUSE");
	return 0;
}
