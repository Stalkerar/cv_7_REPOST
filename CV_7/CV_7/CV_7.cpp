#include <stdio.h>
#include <iostream>

using namespace std;

////////////////// Dìdiènost /////////////////////////
class Shapes
{
protected:
	int _sirka;
	int _vyska;
public:
	Shapes(int sirka,int vyska)
	{
		_sirka = sirka;
		_vyska = vyska;
	}
	double GetArea();
	double GetPerimeter();
};
class Point :public Shapes
{
public:
	Point(int x,int y) : Shapes(x,y)
	{

	}
	double GetArea()
	{
		return 0;
	}
	double GetPerimeter()
	{
		return 0;
	}

};
class Rectangle :public Shapes
{
public:
	Rectangle(int sirka, int vyska) :Shapes(sirka, vyska)
	{

	}
	double GetArea()
	{
		double value = _sirka * _vyska;
		return value;
	}
	double GetPerimeter()
	{
		double value = (2 * _sirka) + (2 * _vyska);
		return value;
	}


};
class Square :public Shapes
{
public:
	Square(int strana) : Shapes(strana, strana)
	{

	}
	double GetArea()
	{
		double value = _vyska * _vyska;
		return value;
	}
	double GetPerimeter()
	{
		double value = 4 * _vyska;
		return value;
	}
};
class Triangle :public Shapes
{
private:
	int _a;
	int _b;
	int _c;
public:
	Triangle(int a, int b,int c) : Shapes(a, b)
	{
		_a = a;
		_b = b;
		_c = c;
	}
	double GetArea()
	{
		double value;
		double s = (_a + _b + _c) / 2;
		value = sqrt(s * (s - _a) * (s - _b) * (s - _c));

		return value;
	}
	double GetPerimeter()
	{
		double value = _a + _b + _c;
		return value;
	}
};
class Circle :public Shapes
{
public:
	Circle(int prumer) : Shapes(prumer, prumer)
	{

	}
	double GetArea()
	{
		double value = (3.14 * (_vyska * _vyska)) / 4;
		return value;
	}
	double GetPerimeter()
	{
		double value = 3.14 * _vyska;
		return value;
	}
};
////////////////////////////////////////////////////////////


/////////////////// Osoba //////////////////////////////////
class Person
{
protected:
	string firstname;
	string secondname;
	int years;
	
	
public:
	Person(string _firstname, string _secondname, int _years)
	{
		firstname = _firstname;
		secondname = _secondname;
		years = _years;
	}
	~Person() 
	{
	}
	void PrintPerson()
	{
		cout << firstname << " " << secondname << " " << years << " ";
	}
	string GetName()
	{
		return firstname;
	}
	string GetSurrname()
	{
		return secondname;
	}
	int GetYears()
	{
		return years;
	}
};


class FamilyMember :public Person
{
private:
	FamilyMember* mother;
	FamilyMember* father;
	int count;
public:
	FamilyMember(Person* human) : Person(human->GetName(),human->GetSurrname(),human->GetYears())
	{
		mother = nullptr;
		father = nullptr;
		FamilyMember** familyArr = (FamilyMember**)malloc(sizeof(FamilyMember) * 10);
		count = 0;
	}
	void addMother(Person* human)
	{
		FamilyMember* mom = new FamilyMember(human);
		mother = mom;
	}
	void addFather(Person* human)
	{
		FamilyMember* dad = new FamilyMember(human);
		father = dad;
	}
	FamilyMember GetMother()
	{
		return mother;
	}
	FamilyMember GetFather()
	{
		return father;
	}
	void printMember(FamilyMember* member)
	{
		cout << member->GetName() << " ";
		putchar('\n');
		putchar('\t');
		cout << member->GetMother().GetName() << " " << member->GetFather().GetName() << " ";
		putchar('\n');
		putchar('\t');
		putchar('\t');
		
	}
	

};



int main()
{
	////////////////// Dìdiènost /////////////////////////
	Point* bod1 = new Point(1, 1);
	printf("Obvod: %lf Obsah: %lf \n", bod1->GetPerimeter(), bod1->GetArea());
	Rectangle* obdelnik1 = new Rectangle(5, 2);
	printf("Obvod: %lf Obsah: %lf \n", obdelnik1->GetPerimeter(), obdelnik1->GetArea());
	Square* ctverec1 = new Square(5);
	printf("Obvod: %lf Obsah: %lf \n", ctverec1->GetPerimeter(), ctverec1->GetArea());
	Triangle* trojuhelnik1 = new Triangle(3, 4, 5);
	printf("Obvod: %lf Obsah: %lf \n", trojuhelnik1->GetPerimeter(), trojuhelnik1->GetArea());
	Circle* kruh1 = new Circle(10);
	printf("Obvod: %lf Obsah: %lf \n", kruh1->GetPerimeter(), kruh1->GetArea());
	////////////////////////////////////////////////////////////

	/////////////////// Osoba /////////////////////////////
	Person* person00 = new Person("Marie", "Nova", 69);
	Person* person0 = new Person("Bohumil", "Novy", 71);
	Person* person1 = new Person("Pavel", "Novy", 76);
	Person* person2 = new Person("Sara", "Nova", 73);
	Person* person4 = new Person("Jirina", "Nova", 41);
	Person* person5 = new Person("Vladko", "Novy", 38);
	Person* person6 = new Person("Ondrej", "Novy", 21);

	FamilyMember* ja = new FamilyMember(person6);
	ja->addFather(person5);
	ja->addMother(person4);
	
	FamilyMember* mom = new FamilyMember(person4);
	mom->addMother(person00);
	mom->addFather(person0);

	FamilyMember* father = new FamilyMember(person5);
	father->addFather(person1);
	father->addMother(person2);

	ja->printMember(ja);
	ja->printMember(mom);
	ja->printMember(father);
	
	
	
	///////////////////////////////////////////////////////



	return 1;
}

