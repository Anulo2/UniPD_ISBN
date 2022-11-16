#ifndef ISBN_H
#define ISBN_H

#include <ostream>
#include <vector>

//n-n-n-x, con n intero e x una singola cifra o una lettera (i quattro campi sono separati da un carattere ‘-’).

class ISBN
{
public:

	ISBN(int field1_in, int field2_in, int field3_in, char field4_in);
	ISBN(std::string isbn);
	
	ISBN& operator=(ISBN a);
	
	int get_field1(void) const { return field1; }
	int get_field2(void) const { return field2; }
	int get_field3(void) const { return field3; }
	char get_field4(void) const { return field4; }
	
	bool is_valid(void) const { return (field4 < 'a' || field4 > 'z') && (field4 < 'A' || field4 > 'Z') && (field4 < '0' || field4 > '9');}

	class InvalidIdentifier {};
	
private:
	int field1;
	int field2;
	int field3;
	char field4;
	};
	
bool operator==(ISBN a, ISBN b);

std::ostream& operator<<(std::ostream& os, ISBN &a);
std::ostream& operator<<(std::ostream& os, ISBN *a);

#endif // ISBN_H

