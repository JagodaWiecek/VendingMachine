#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>

/**
klasa Cash ma na celu sprawdzic czy wprowadzana wartosc jest poprawna czy nie.
*/
class Cash
{
	double money=0; ///< zmienna do ktorej jest przypisywana wartosc wprowadzana z zewnatrz
	double tab[6] = {5.0, 2.0, 1.0, 0.50 ,0.20, 0.10}; ///< jest to tablica, ktora zawiera wartosci 5, 2, 1, 0.5, 0.2 i 0.1 jako wartosci double. To na jej bazie sa sprawdzane wartoœci wprowadzane
public:
///metoda ktora daje dostep do zmienienia prywatnej zmiennej "money"
///@param const double& money zmienna ktora zostanie przypisana zmiennej klasowej
	void SetMoney(const double & money); 
///metoda ktora wyswietla jaka wartosc sie znajduje w zmiennej "money"
	double GetMoney(); 
///metoda ktora zwraca true albo false w zaleznosci czy w zmiennej "money" znajduje sie wartosc identyczna do jednej z zmiennych w tablicy "tab"
	bool Check(); 
///Konstruktor domyslny klasy
	Cash();
///Destruktor klasy
	~Cash();
};




/**
class Drink definiuje podstawowa klase napoju, nie jest wykorzystywany bezposrednio w programie.
*/
class Drink
{

	std::string drink_name;///<zmienna nazwa napoju, w niej jest przechowywana nazwa kazdego napoju z programu 
	double price; ///<zmienna double w ktorej jest przechowywana cena kazdego napoju
	std::string code; ///<zmienna ktora przechowuje kod do kazdego napoju
	

public:
///Konstruktor domyslny klasy
	Drink();
///Destruktor klasy
	~Drink();
///Metoda ustawiajaca zmienna "drink_name" klasy Drink
///@param const std::string& name zmienna tekstowa ktora jest przypisywana do zmiennej klasowej "drink_name"
	void SetName(const std::string& name); 
///Metoda ustawiajaca zmienna "price" klasy Drink
///@param const double& pr zmienna zmiennoprzecinkowa ktora ustawia zmienna klasowa "price"
	void SetPrice(const double& pr);
///Metoda ustawiajaca zmienna "code" klasy Drink
///@param const std::string& c zmienna tekstowa ustawiajaca zmienna klasowa "code"
	void SetCode(const std::string& c); 
///Metoda zwracajaca wartosc zmiennej "drink_name" w klasie Drink
	std::string GetName();
///Metoda zwracajaca wartosc zmiennej "price" w klasie Drink
	double GetPrice();
///Metoda zwracajaca wartosc zmiennej "code" w klasie Drink
	std::string GetCode();
///Metoda wirtualna zwracajaca zmienna "size" albo "amount" w klasach dziedziczacych
	virtual int GetSizeOrAmount()=0;
///Metoda wierualna zmieniajaca zmienne "size" albo "amount" w klasach dziedziczacych
	virtual int UpdateSA() = 0;
///Metoda wirtualna, ktora jest zdefiniowana dla Drink i jej klas pochodnych. Drukuje wszystkie zmienne w ustalonej kolejnosci w konsoli. Jest wykorzystywany w liscie
///@param std::ostream& out zmienna strumieniowa do przeslania czegos na konsole
	virtual void print(std::ostream& out);
///Zdefiniowana metoda wirtualna zdefinowana dla klasy Drink i jej klas dziedziczacych. Przesyla/Drukuje zmienne w pliku w zadeklarowanej kolejnosci
///@param std::ostream& out zmienna strumieniowa do przeslania czegos do pliku
	virtual void printtf(std::ostream& out);
///Metoda wirtualna istotna dla klas dziedziczacych
	virtual bool CheckAS()=0;
///Metoda do estetycznego wyswietlania zmiennych na ekranie, wykorzystywana w klasie Interface w zaleznosci od wprowadzonej listy do programu.
    virtual void showDrink();



};
std::ostream& operator<<(std::ostream& out, Drink& d);
/** 
klasa CupDrinks dziedziczy po klasie Drink. Zawiera dodatkowa zmienna "size" i metody z nia zwiazane. 
CupDrinks odzwierciedla cieple napoje w kubkach w automatach z napojami.
*/
class CupDrinks : public Drink
{
	
	int size;///<Zmienna calkowita "size", odzwierciedla ilosc napoju w "baniaku" wewnatrz automatu w minilitrach.
	
public:
///Konstruktor domyslny klasy
	CupDrinks();
///Destruktor klasy
	~CupDrinks();
///Konstruktor wieloargumentowym ktory przypisuje od razu wartosci wprowadzanych zmiennych do zmiennych klasy
	CupDrinks(std::string name, int size, double price, std::string code);
///Metoda zmieniajaca wartosc zmiennej "size".
///@param const int& s zmienna calkowita ustawiajaca wartosc zmienna klasowa "size"
	void SetSize(const int & s);
///Metoda zwracajaca wartosc zmiennej "size".
	int GetSize();
///Metoda drukujaca zmienne CupDrinks w konsoli. Rozni sie od "printtf" tym, ze nie drukuje zmiennej "size" na ekran.
///Jest to tak zrobione poniewaz osoba kupujaca nie widzi ile jest danego napoju w maszynie z cieplymi napojami.
///@param std::ostream& out zmienna strumieniowa do przeslania czegos na konsole
	void print(std::ostream& out);
///Metoda przesylajaca zmienne w zainicjowanej kolejnosci do pliku.
///@param std::ostream& out zmienna strumieniowa do przeslania czegos do pliku
	void printtf(std::ostream& out);
///Metoda ktora w tej klasie zwraca zmienna "size". Metoda potrzebna by dostac sie do owej zmiennej korzystajac z klasy List, ktora opiera sie na klasie Drink
	int GetSizeOrAmount();
///Metoda ktora w tej klasie zmniejsza wartosc zmiennej "size" o 250[ml]. SA -> Size/Amount
	int UpdateSA();
///Metoda sprawdzajaca czy zmienna jest wieksza badz rowna 250[ml]. Jesli by zwrocila false, to nie mozna modyfikowac wartosci "size"
	bool CheckAS();
///Metoda do estetycznego wyswietlania zmiennych na ekranie, wykorzystywana w klasie Interface w zaleznosci od wprowadzonej listy do programu.
	void showDrink();
	
	
};
std::ostream& operator<<(std::ostream& out, CupDrinks& d);
std::ofstream& operator<<(std::ofstream file, CupDrinks& d);
/**
Klasa BottleDrinks dziedziczy po klasie Drink. Zawiera dodatkowa zmienna "amount" i metody z nia zwiazane.
BottleDrinks odzwierciedla zimne napoje butelkowane w automacie z napojami.
*/
class BottleDrinks : public Drink
{
	int amount;///<Zmienna calkowita "amount" odzwierciedla ilosc butelek napoju w automacie.

public:
///Konstruktor domyslny klasy
	BottleDrinks();
///Destruktor klasy
	~BottleDrinks();
///Konstruktor wieloargumentowym ktory przypisuje od razu wartosci wprowadzanych zmiennych do zmiennych klasy
	BottleDrinks(std::string name,int amount,double price,std::string code);
///Metoda ustawiajaca wartosc w "amount".
///@param const int& a zmienna calkowita ktora ustawia zmienna klasowa "amount"
	void SetAmount(const int & a);
///Metoda zwracajaca wartosc przechowywana w zmiennej "amount".
	int GetAmount();
///Metoda drukujaca zmienne klasy na konsole w zainicjowanej kolejnosci
///@param std::ostream& out zmienna strumieniowa do przeslania czegos na konsole
	void print(std::ostream& out);
///Metoda przesylajaca wartosci zmiennych w klasie do podanego pliku 
///@param std::ostream& out zmienna strumieniowa do przeslania czegos do pliku
	void printtf(std::ostream& out);
///Metoda zwracajaca w tej klasie wartosc "amount", wymagana przy uzywaniu List
	int GetSizeOrAmount();
///Metoda zmieniajaca wartosc SA->Size/Amount. W tej klasie zmniejsza wartosc w zmiennej "amount" o 1.
	int UpdateSA();
///Metoda sprawdzajaca czy zmienna "amount" jest wieksza od 0, jesli jest rowna 0 to zwroci false.
	bool CheckAS();
///Metoda do estetycznego wyswietlania zmiennych na ekranie, wykorzystywana w klasie Interface w zaleznosci od wprowadzonej listy do programu.
	void showDrink();
};
std::ostream& operator<<(std::ostream& out, BottleDrinks& d);
/**
Klasa Element jest konieczna do poprawnego dzialania klasy List. Zawiera wskaznik na zmienna klasy Drink oraz "nastepna" zmienna klasy Element.
*/
class Element
{
public:
	///Wskaznik na zmienne klasy Drink 
	Drink* d;
	///Wskaznik na natepna zmienna klasy Element 
	Element* next = nullptr;
	///Konstruktuk klasy Element
	///@param Drink* D wskaznik na zmienne klasy Drink
	Element(Drink* D);
	///Destruktor klasy Element, który usuwa wskaŸnik d
	~Element();
	///Metoda ktora tworzy nowy wskaznik na kolejny element klasy Drink
	///@param Drink* D wskaznik na zmienne klasy Drink
	void add(Drink* D);
	///Metoda zwracajaca pojedyncza zmienna z listy na podstawie podanej zmiennej n
	///@param unsigned int n zmienna calkowita nieujemna, sluzy do wydobycia odpowiedniej n-tej zmiennej w liscie
	Drink& get(unsigned int n);
	///Metoda wyswietlajaca wszystkie wybrane zmienne wszystkich wskaznikow klasy
	void showAll();
	///Metoda zwraza ile lista zawiera wskaznikow
	int size();
	///Metoda usuwajaca i zerujaca wskazniki
	void erase();
	///Metoda zapisujaca zmienne, na ktore wskazuje wskaznik,do pliku.
	///@param std::ostream& file strumien do ktorego beda przesylane zmienne do zapisu
	void save(std::ofstream& file);
};
/**
Klasa List zawiera wskaznik na pierwszy element klasy Element i metody z nia zwiazane
*/
class List
{
public:
	///Wskaznik na pierwszy element
	Element* first = nullptr;
	///Metoda ktora zmienia na co wskazuje wskaznik "first" przy pierwszym dodawaniu do listy
	///@param Drink* D wskaznik na zmienne klasy Drink
	void add(Drink* D);
	///Metoda zwracajaca wskaznik na wybrane zmienne klasy Drink
	///@param unsigned int n zmienna calkowita nieujemna, sluzy do wydobycia odpowiedniej n-tej zmiennej w liscie
	Drink& get(unsigned int n);
	///Metoda wyswietlajaca wszystkie wybrane zmienne wszystkich wskaznikow klasy
	void showAll();
	///Metoda zwraza ile lista zawiera wskaznikow
	int size();
	///Metoda usuwajaca i zerujaca wskazniki
	void erase();
	///Metoda zapisujaca zmienne, na ktore wskazuje wskaznik,do pliku.
	///@param std::ostream& file strumien do ktorego beda przesylane zmienne do zapisu
	void save(std::ofstream& file);
};


/** 
Klasa Interface odpowiada za sprawdzanie warunkow, wyswietlanie wszytskiego na ekranie. Zawiera zmienna "total", w niej zawiera sie ostateczna wartosc "pieniedzy" po wprowadzeniu monet.
*/
class Interface
{
	double total = 0; ///<zmienna zmienna calkowita ktora bedzie prowadzana z konsoli
public:
///Metoda zwracajaca wartosc jaka aktualnie znajduje sie w zmiennej "total"
	double GiveTotal();
///Metoda ktora dodaje do zmiennej "total" wartosc jaka znajduje sie w zmiennej "money"
///@param const double& money zmienna ktora jest dodawana do zmiennej klasowej "total", czyli zmienna total jest wieksza o zmienna money
	double UpdateTotal(const double& money);
///Metoda ktora usuwa ze zmiennej "total" ilosc zawarta w zmiennej "money"
///@param const double& money zmienna ktora jest usuwana z zmiennej klasowej "total". Przed wykonaniem tej operacji jest sprawdzane czy zmienna "money" jest wieksza od total
	double ChangeTotal(const double& money);
///Metoda zerujaca wartosc w zmiennej "total"
	double NullTotal();
///Metoda Animacja wykorzystywana przy konczeniu programu, kiedy ma byc "wydawana reszta".
///@param List& l potrzebne przy wyswietlaniu animacji w konsoli
	void MakeChange(List& l);
///Metoda Animacja wykorzystywana przy wydawaniu produktu po wpisaniu kodu produktu. Zmienia wartosc size albo amount w zaleznosci od rodzaju listy
///@param List& l potrzebne do zmienienia wartosci zapisanych w liscie
///@param int indx zmienna calkowita wskazujaca na zmienne w liscie l o indeksie "indx"
	void GiveProduct(List& l,int indx);
///Konstruktor Interface, na wstepie potrzebuje pliku wejsciowego, tekstu informacji jaki to bedzie automat i pusta zmienna List do ktorej beda zamieszcza zmienne z pliku
///@param std::string& info zmienna tekstowa ktora jest wpisywana na starcie programu. Jest to informacja w programie do stworzenia odpowiedniego wskaznika do listy i poprawnego zaladowania zmiennych
///@param List& l klasa List do ktorej beda wprowadzane zmienne z pliku wejsciowego 
	Interface(std::string& info,List& l);
///Metoda wyswietlajaca wszytskie zmienne listy na konsoli z odpowiednimi zmiennymi w zaleznosci od wprowadzanej listy.
///@param List& l zawiera zmienne do wyswietlenia wszystkiego na konsoli
	void show(List& l);
///Metoda sprawdzajaca czy wpisana wartosc, ktora ma byc dodana do zmiennej total, to faktycznie liczba double czy ciag znakow. Zwraca true gdy wprowadzany tekst jest poprawna liczba zmiennoprzecinkowa
///@param std::string str zmienna tekstowa ktora jest sprawdzana
	bool doublecheck(std::string str);
///Metoda sprawdzajaca czy w liscie znajduje sie zmienna drink ktora ma taka sama zmienna Drink::code co sprowadzona zmienna "code"
///@param List& l lista na ktorej jest sprawdzane czy wprowadzany kod zawiera sie w liscie
///@param int& sth zmienna ktora zapisuje indeks listy w ktorej jest poprawny kod. Jesli nie ma kodu w liscie, to sth=0
///@param std::string code zmienna tekstowa wprowadzana przez uzytkownika z konsoli
///@param bool& what zmienna ktora zapisuje true albo false. Jesli wprowadzony kod z konsoli nie bedzie zawieral sie w ktorejs zmiennej listy, what=false
	void TestCode(List& l, int& sth, std::string code, bool& what);
///Metoda sprawdza czy wartosc w zmiennej "total" jest wieksza badz rowna zmiennej "price".
///@param List& l lista potrzebna do sprawdzenia zmiennej w liscie
///@param int& sth wprowadzona zmienna calkowita by nie szukac juz konkretnej wartosci w liscie, tylko sprawdzyc od razu czy wartosc w liscie sie zgadza
///@param bool& what zwraca false gdy zmienna "total" bedzie mniejsza od zmiennej "price" zawartej w liscie pod indeksem "sth"
	void TestTotal(List& l, int& sth,bool& what);
///Metoda do "wrzucania monet". 
///@param List& l wymagane do wyswietlania wszytskiego na konsoli
	void deposit(List& l);
///Metoda w ktorej zawieraja sie wszytkie metody programu. 
///Zawiera w sobie metode deposit do wprowadzenia monet, a nastepnie wprowadzanie kodu uprawgnionego napoju.
///Nastepnie sprawdza czy wprowadzony kod istnieje uzywajac metody  TestCode(..). Jesli zmienna w metodzie zwroci false, bedzie sie wykonywalo petle while tak dlugo az zmienna whta=true.
///Program bedzie narzucac wtedy wpisanie innego kodu
///Gdy kod bedzie poprawny, bedzie sprawdane czy jest wystarczajaca ilosc napoju w automacie. Jesli w automacie z napojami zimnymi bedzie zero butelek z napojem, metoda zwroci false. Gdy w automacie z napojami cieplymi 
///bedzie miec mniej niz 250[ml], metoda zwroci false. W czasie trwania tego sprawdzenia rowniez jest wykorzystywana metoda "TestCode(..) gdyz jesli nie ma odpowiedniej ilosci napoju, nalezy podac inny kod.
///metoda "TestCode(..) sprawdzi ponownie czy kod w ogole istnieje
///Ostatecznie zostanie sprawdzone czy w zmiennej "total" jest wystarczajaca wartosc by wydac produkt. Jesli total<produckPrice, to bedzie wykonana ponownie metoda "Deposite(..)" dopuki total>=produktPrice.
///Ostatecznie program zapyta czy konsument bedzie chcial kontynuowac zakupy, czy zakonczyc. Jesli uzytkownik wprowadzi slowo kluczowe "yes" program zapyta sie o miejsce zapisania postepu.
///Ponadto program zawiera slowo kluczone "end", jesli uzytkownik bedzie chcial natychmiastowo zakonczyc program przy kazdym wprowadzaniu wartosci z konsoli  
///Gdy zostana wprowadzone 
///@param List& l wymagane do wyswietlania wszytskiego na konsoli
	void enterCode(List&l);
///Metoda sprawdzajaca wpisywane stringi w trakcie programu, gdy zostanie wprowadzony odpowiedni komunikat, zakonczy program,
///jesli nie, to rekurencyjnie odpali program jeszcze raz.
///Metoda wlacza animacje GiveProduct, z ktorej sa zmniejszane zmienne z podanej listy.
///Nastepnie zostanie wyswietlone pytanie o kontynuowaniu programu czy nie. Komunikat ten zostanie prowadzony do metody End(..), ktora zakonczy program badz odpali go ponownie
///metoda entercode(..)
///@param List& l lista wymagana do zaktualizowania zmiennych size/amount zawartoch w liscie na podstawie podanego indeksu
///@param int& indx zmienna wskazujaca na konkretna czesc listy
	void Finish(List& l, int& indx);
///Metoda zakonczenia programu, zapisu danych i uwolnienia pamieci
///@param std::string& str zmienna tekstowa odpowiadajaca komunikatowi z metody Finish(..). W zaleznosci od komunikatu, albo wylaczy program, albo nie zrobi nic
///@param List& l potrzna do zapisu zmiennych do pliku, jest na niej rowniez wykonana jej metoda erase(), ktora czysci pamiec.
	void End(std::string &str,List& l);
}; 


#endif 