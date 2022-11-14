#include "isbn.h"

ISBN::ISBN(int field1_in, int field2_in, int field3_in, char field4_in): field1{field1_in}, field2{field2_in}, field3{field3_in}, field4{field4_in}{
	if ((field4 < 'a' || field4 > 'z') && (field4 < 'A' || field4 > 'Z') && (field4 < '0' || field4 > '9')){
		throw InvalidIdentifier();
	}
}

ISBN& ISBN::operator=(ISBN a)
{
    field1 = a.field1;
	field2 = a.field2;
	field3 = a.field3;
	field4 = a.field4;
	    
    return *this;
}

bool operator==(ISBN a, ISBN b)
{
	return a.get_field1() ==  b.get_field1() && a.get_field2() ==  b.get_field2() && a.get_field3() ==  b.get_field3() && a.get_field4() ==  b.get_field4();
}

std::ostream& operator<<(std::ostream& os, ISBN a)
{
	return os << a.get_field1() << "-" << a.get_field2() << "-" << a.get_field3() << "-" << a.get_field4();
}