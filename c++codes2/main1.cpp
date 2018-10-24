#include <iostream>
#include <string>

using namespace std;

class String {
	
	string x;
	
public:
	
	String(const string& x): x(x) {}
	
	String operator+(const String& s) {
		String dest(string(""));
		dest.x = this->x + s.x;
		return dest;
	}
	
	friend ostream& operator<<(ostream& stream, const String& s) {
		stream << s.x;
		return stream;
	}
	
};



int main() {
	
	String s1(string("Hello "));
	String s2(string("World."));
	
	String s3 = s1 + s2;
	
	cout << s3 << endl;
	
	
	return 0;
}
