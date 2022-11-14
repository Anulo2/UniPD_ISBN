class Date {
public:
	class Invalid {}; // per riportare errori
	Date (int y, int m, int d); // check e inizializza
	
	int get_day(void) {return d;}
	int get_month(void) {return m;}
	int get_year(void) {return y;}

private:
	int y, m, d;
	bool is_valid(void); // ritorna true se la data è valida
	static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};