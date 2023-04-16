#include <iostream>
#include <string>
using namespace std;

class Node {

private:
	unsigned long longVal = 0;
	int value = 0;
	string val = "";
	Node* NextNode;

public:  // Constructors

	Node(int v)
	{
		value = v;
		NextNode = NULL;
	}

	Node(long v, Node* newNextNode)
	{
		longVal = v;
		NextNode = newNextNode;
	}
	Node(long v)
	{
		longVal = v;
		NextNode = NULL;
	}

	Node(int v, Node* newNextNode)
	{
		value = v;
		NextNode = newNextNode;
	}
	Node(string v)
	{
		this->val = v;
		NextNode = NULL;
	}

	Node(string v, Node* newNextNode)
	{
		this->val = v;
		NextNode = newNextNode;
	}
	friend class List;

	friend class Test;
};

typedef Node* PointerNode; //Alias

class List {

private:
	PointerNode head;

public:
	List() { head = NULL; }
	List(PointerNode newHead) {
		head = newHead;
	}
	//~List();
	void unshift(string v); // Insert at Beginning
	void push(string v); // Insert at End
	void pushLong(long v);
	void unshift(int v); // Insert at Beginning
	void push(int v); // Insert at End
	void splice(int v, int pos); // Insert at Index Position
	bool isEmpty() { return head == NULL; }
	void display();
	void displayVal();
	Node* pop();
	void shift();
	void removeAtIndex(int pos);
	int length();
	bool searchElement(int element);
	List* splitNumbers(int number);
	List* splitNumbersLong(long num);
	int readElementByIndex(int index);
	bool isSortedList();
	void displayLong();
	void unshiftLong(long v);
	void createNewListAndPattern(bool isStart, List& newList);
	void reverse();
	void createNewList(bool isStart, List& list);
	bool hasRepeatedElement(List& list);
	friend class Test;
};

List* List::splitNumbers(int num)
{
	List* result = new List();
	if (num > 0)
	{
		while (num != 0)
		{
			int temp = num % 10;
			result->unshift(temp);
			num = num / 10;
		}
	}
	return result;
}

List* List::splitNumbersLong(long num)
{
	List* result = new List();
	if (num > 0)
	{
		while (num != 0)
		{
			int temp = num % 10;
			result->unshiftLong(temp);
			num = num / 10;
		}
	}
	return result;
}

int List::length() {
	int cont = 0;

	PointerNode aux = head;
	if (isEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
		cout << endl;
	}

}

void List::unshift(string v)
{
	if (isEmpty())
	{
		head = new Node(v);
	}
	else
	{
		head = new Node(v, head);
	}
}

void List::unshift(int v)
{
	if (isEmpty())
	{
		head = new Node(v);
	}
	else
	{
		head = new Node(v, head);
	}
}

void List::unshiftLong(long v)
{
	if (isEmpty())
	{
		head = new Node(v);
	}
	else
	{
		head = new Node(v, head);
	}
}

void List::push(string v)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(v);
	}
}

void List::push(int v)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(v);
	}
}

void List::pushLong(long v)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(v);
	}
}

void List::splice(int v, int pos)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else {
		if (pos <= 1)
		{
			unshift(v);
		}
		else {
			Node* aux = head;
			int i = 2;
			while ((i != pos) && (aux->NextNode != NULL)) {
				i++;
				aux = aux->NextNode;
			}
			PointerNode newNodeFirst = new Node(v);
			newNodeFirst->NextNode = aux->NextNode;
			aux->NextNode = newNodeFirst;
		}
	}
}

Node* List::pop()
{
	if (isEmpty()) {
		return NULL;
	}
	else {

		if (head->NextNode == NULL)
		{
			PointerNode temp = head;
			head = NULL;
			return temp;
		}
		else {

			PointerNode aux = head;
			while (aux->NextNode->NextNode != NULL) {
				aux = aux->NextNode;
			}

			PointerNode temp = aux->NextNode;
			aux->NextNode = NULL;

			return temp;
		}
	}
}

void List::shift()
{
	if (isEmpty()) {
		cout << "Empty List:" << endl;
	}
	else {
		if (head->NextNode == NULL)
		{
			PointerNode temp = head;
			head = NULL;
			delete temp;
		}
		else
		{
			PointerNode aux = head;
			head = head->NextNode;
			delete aux;
		}
	}
}

void List::removeAtIndex(int index) {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		if ((index > length()) || (index < 0)) {
			cout << "An Index should be greater than zero" << endl;
		}
		else {
			if (index == 1)
			{
				PointerNode temp = head;
				head = head->NextNode;
				delete temp;
			}
			else {
				int cont = 2;
				PointerNode aux = head;
				while (cont < index) {
					aux = aux->NextNode;
					cont++;
				}
				PointerNode temp = aux->NextNode;
				aux->NextNode = aux->NextNode->NextNode;
				delete temp;
			}
		}
	}
}

void List::display()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty List";
	}
	else
	{
		aux = head;
		while (aux)
		{
			if (aux->NextNode == NULL)
			{
				cout << aux->value;
			}
			else {
				cout << aux->value << ", ";
			}

			aux = aux->NextNode;
		}
		cout << endl;
	}
}

void List::displayLong()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty List";
	}
	else
	{
		aux = head;
		while (aux)
		{
			if (aux->NextNode == NULL)
			{
				cout << aux->longVal;
			}
			else {
				cout << aux->longVal << ", ";
			}

			aux = aux->NextNode;
		}
		cout << endl;
	}
}

void List::displayVal()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty List";
	}
	else
	{
		aux = head;
		while (aux)
		{
			if (aux->NextNode == NULL)
			{
				cout << aux->val;
			}
			else {
				cout << "\n" << aux->val << ", ";
			}

			aux = aux->NextNode;
		}
		cout << endl;
	}
}

bool List::searchElement(int element)
{
	bool searchElement = false;
	if (head != NULL) {
		Node* aux = head;
		while (aux)
		{
			if (aux->value == element)
			{
				searchElement = true;
			}
			aux = aux->NextNode;
		}
	}
	return searchElement;
}

int List::readElementByIndex(int index)
{
	Node* aux;
	if (head == NULL) {
		return -1;
	}
	else
	{
		int count = 0;
		aux = head;
		while (aux)
		{
			if (count == index)
			{
				return aux->value;
			}
			count++;
			aux = aux->NextNode;
		}
		return -1;
	}
}

void List::reverse()
{
	PointerNode prev = NULL;
	PointerNode next = head;
	while (head != NULL)
	{
		head = head->NextNode;
		next->NextNode = prev;
		prev = next;
		next = head;
	}
	head = prev;
}

bool List::isSortedList() {

	if (head != NULL) {
		Node* aux;
		aux = head;
		while (aux != NULL)
		{
			if (aux->NextNode != NULL && aux->value > aux->NextNode->value)
			{
				return false;
			}
			aux = aux->NextNode;
		}
	}
	return true;
}

void List::createNewList(bool isStart, List& newList) {
	if (isStart)
	{
		newList.unshift(1);
		newList.unshift(0);
		newList.unshift(1);
	}
	else {
		newList.push(0);
		newList.push(1);
		newList.push(0);
	}
}

void List::createNewListAndPattern(bool isStart, List& newList) {
	if (isStart)
	{
		newList.unshift(1);
		newList.unshift(0);
		newList.unshift(1);
	}
	else {
		newList.push(0);
		newList.push(-1);
		newList.push(0);
	}
}

bool List::hasRepeatedElement(List& newList) {
	List* unique = new List();

	if (newList.head != NULL) {
		Node* aux = newList.head;
		while (aux)
		{
			if (!unique->searchElement(aux->value))
			{
				unique->push(aux->value);
			}
			aux = aux->NextNode;
		}
	}
	return unique->length() != newList.length();
}

class Test {
private:

public:
	Test() { }
	void UNO(List* LTrabajo);
	void DOS(int num1, int num2, int num3);
	void TRES(int num1, int num2, int num3, int num4);
	void CUATRO(long num);
};

//Exercise 1
void Test::UNO(List* LTrabajo)
{
	if (LTrabajo->isEmpty()) {
		cout << "Lista Esta Vacia \n\n" << endl;
	}
	else if (LTrabajo->length() == 1)
	{
		List* newList = new List();
		newList->createNewList(true, *newList);
		newList->push(LTrabajo->head->value);
		newList->createNewList(false, *newList);
		newList->display();
	}
	else if (LTrabajo->hasRepeatedElement(*LTrabajo)) {
		cout << "Lista Tiene Elementos Repetidos \n\n" << endl;
		LTrabajo->display();
		cout << "\n";
	}
	else if (LTrabajo->isSortedList()) {
		cout << "Lista Esta Ordenada \n\n" << endl;
		LTrabajo->display();
		cout << "\n";
	}
	else {
		Node* aux;
		aux = LTrabajo->head;
		while (aux != NULL)
		{
			if (aux->NextNode != NULL && aux->value > aux->NextNode->value)
			{
				List* newList = new List();
				newList->createNewList(true, *newList);

				while (aux->NextNode != NULL && aux->value > aux->NextNode->value) {
					newList->push(aux->value);

					if (aux->value != 0)
					{
						newList->push(aux->value);
					}
					else {
						newList->push(aux->value * -1);
					}

					aux = aux->NextNode;
				};

				newList->createNewList(false, *newList);

				newList->display();
			}
			
			else {
				List* newReversedList = new List();

				while (aux->NextNode != NULL && aux->value < aux->NextNode->value) {

					if (aux->value != 0)
					{
						newReversedList->push(aux->value);
					}
					else {
						newReversedList->push(aux->value * -1);
					}

					newReversedList->push(aux->value);

					aux = aux->NextNode;
				};

				newReversedList->push(aux->value * -1);
				newReversedList->push(aux->value);

				newReversedList->reverse();
				newReversedList->createNewList(true, *newReversedList);
				newReversedList->createNewList(false, *newReversedList);

				newReversedList->display();
			}
			

			aux = aux->NextNode;
		};
	}
	
};

//Exercise 2
void Test::DOS(int num1, int num2, int num3)
{
	
	if (num1 <= 0 || num2 <= 0 || num3 <= 0)
	{
		num1 = std::abs(num1);
		num2 = std::abs(num2);
		num3 = std::abs(num3);
	}

	List* numL1 = (new List())->splitNumbers(num1);

	List* numL2 = (new List())->splitNumbers(num2);

	List* numL3 = (new List())->splitNumbers(num3);

	if (numL1->length() % 2 == 0 || numL2->length() % 2 == 0 || numL3->length() % 2 == 0)
	{
		cout << "Alguno de los Numeros no es impar y no es valido" << endl;
		return;
	}

	if (!(numL1->length() == numL2->length() && numL2->length() == numL3->length()))
	{
		cout << "Alguno de los Numeros no es del mismo largo y no es valido" << endl;
		return;
	}

	if (numL1->length() < 2 || numL2->length() < 2 || numL3->length() < 2)
	{
		cout << "Algun numero es menos de 3 digitos y no son validos" << endl;
		return;
	}

	List* output = new List();

	int cont = 0;

	int index1 = 0;

	int index2 = numL1->length() - 1;

	bool isForward = true;

	int length = (numL1->length() );

	int centerIndexL1 = ((numL1->length()) / 2);

	int centerIndexL2 = ((numL2->length()) / 2);

	int leftIndex = centerIndexL1 - 1;

	int rightIndex = centerIndexL1 + 1;

	bool isSecondList = true;

	cout << "Trenza " << "\n" << endl;
	while (cont < length) {

		if (isForward)
		{
			cout << numL1->readElementByIndex(index1) << " ^ 3 -> ";
			cout << numL2->readElementByIndex(index2) << " ^ 2 -> ";
			cout << numL3->readElementByIndex(index1) << " ^ 3 -> ";
			output->push((numL1->readElementByIndex(index1) * numL1->readElementByIndex(index1) * numL1->readElementByIndex(index1) )+
				 (numL2->readElementByIndex(index2) * numL2->readElementByIndex(index2)) +
				 (numL3->readElementByIndex(index1) * numL3->readElementByIndex(index1)* numL3->readElementByIndex(index1)));

		}
		if (!isForward)
		{
			cout << numL3->readElementByIndex(index2) << " ^ 2 -> ";
			cout << numL2->readElementByIndex(index1) << " ^ 3 -> ";
			cout << numL1->readElementByIndex(index2) << " ^ 2 -> ";
			output->push((numL3->readElementByIndex(index2) * numL3->readElementByIndex(index2)) +
				(numL2->readElementByIndex(index1) * numL2->readElementByIndex(index1)* numL2->readElementByIndex(index1)) +
				(numL1->readElementByIndex(index2) * numL1->readElementByIndex(index2)));
		
			index1++;
			index2--;
		}
		isForward = !isForward;

		cont++;
	}

	cout << "\n\nPotencias \n" << endl;
	output->display();

	int sum = 0;
	PointerNode sumOutput = output->head;

	while (sumOutput != NULL) {
		sum += sumOutput->value;
		sumOutput = sumOutput->NextNode;
	}
	cout << "\nTotal " << sum << "\n" << endl;
};

//Exercise 3
void Test::TRES(int num1, int num2, int num3, int num4) {
	
	if (num1 <= 0 || num2 <= 0 || num3 <= 0 )
	{
		num1 = std::abs(num1);
		num2 = std::abs(num2);
		num3 = std::abs(num3);
	}
	// num1 Trabajo => 732439
	// num2 Incluir => 8
	// num3 Cantidad => 5
	// num4 Buscar => 3
	
	int power = 1;

	while (num1 > power) {
		power *= 10;
	}
		
	power /= 10;

	List* newList = new List();
	
	while (num1 != 0)
	{
		int digit = num1 / power;

		if (digit == num4)
		{
			newList->display();
			newList = new List();
			List* newListpattern = new List();
			//Init Pattern
			newListpattern->createNewList(true, *newListpattern);
			//ancestor
			newListpattern->unshift(digit - 1);
			//Include Times
			int cont = 0;
			while (cont < num3) {
				newListpattern->push(num2);
				cont++;
			}
			//Original value
			newListpattern->push(digit);
			//Reverse
			newListpattern->push(digit * -1);
			//Second Time After Reverse
			cont = 0;
			while (cont < num3) {
				newListpattern->push(num2);
				cont++;
			}
			//End Pattern
			newListpattern->createNewListAndPattern(false, *newListpattern);
			//Negative Successor
			newListpattern->push((digit + 1) * -1);
			newListpattern->display();
		}
		else {
			
			newList->push(digit);
			
		}
		
		if (digit != 0) {
			num1 = num1 - digit * power;
		}
		
		if (power != 1) {
			power /= 10;
		}
		if (num1 == 0)
		{
			newList->display();
		}
	}
	
};

//Exercise 4
void Test::CUATRO(long num) {

	if (num < 0 )
	{
		num = std::abs(num);
	}
	List* numL1 = (new List())->splitNumbersLong(num);

	List* output = new List();

	PointerNode aux = numL1->head;

	while (aux != NULL) {
		
		if (aux->longVal != 0)
		{
			output->pushLong(aux->longVal);
		}
		else {
			output->pushLong(101);
		}
		aux = aux->NextNode;

	}

	cout << "Numero a Lista de Original \n" << endl;
	numL1->displayLong();
	cout << "\n\nLista de Salida \n" << endl;
	output->displayLong();
};

int main()
{
	//Init Test
	Test test;

	cout << "***************************************************************************************" << endl;
	cout << "UNO" << "\n" << endl;

	List* ListaTrabajo = new List();
	/*ListaTrabajo->push(6);
	//ListaTrabajo->push(-1);
	ListaTrabajo->push(-1);
	ListaTrabajo->push(2);
	ListaTrabajo->push(7);
	ListaTrabajo->push(8);
	ListaTrabajo->push(16);
	ListaTrabajo->push(-100);
	ListaTrabajo->push(-200);*/

	ListaTrabajo->push(-99);
	ListaTrabajo->push(36);
	ListaTrabajo->push(-88);
	ListaTrabajo->push(0);
	ListaTrabajo->push(100);
	ListaTrabajo->push(200);

	test.UNO(ListaTrabajo);

	cout << endl;

	cout << "***************************************************************************************" << endl;
	
	cout << "DOS" << "\n" << endl;
	
	test.DOS(1234567, 1890265, -9032143);
	
	cout << endl;

	cout << "***************************************************************************************" << endl;

	cout << "TRES" << "\n" << endl;

	// Numero Trabajo => 732439
	// Numero Incluir => 8
	// Numero Cantidad => 5
	// Numero Buscar => 3
	test.TRES(732439,8,5,3);

	cout << endl;

	cout << "***************************************************************************************" << endl;

	cout << "CUATRO" << "\n" << endl;

	unsigned long val = -345010890;

	test.CUATRO(val);

	cout << endl;

	cout << "***************************************************************************************" << endl;

	cin.get();
	return 0;
}
