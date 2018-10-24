#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BigInteger {

public:
    
    vector<int> elems;
    
    BigInteger(const string& x) {
        for (int i = 0; i < x.size(); i++) {
            elems.push_back((int)(x[i] - '0'));
        }
    }
    
    BigInteger() {}
  
    BigInteger operator*(const BigInteger& x) {
        
        int N = x.elems.size(), M = this->elems.size();
        
        int max_prod_length = N + M;
    
        BigInteger prod;
        prod.elems = vector<int>(max_prod_length, 0);
        
        /* Multiplication */
        for (int i = 0; i < N; i++) {
        
            int carry = 0;
            for (int j = 0; j < M; j++) {
            
                prod.elems[i+j] += carry + x.elems[i] * this->elems[j];
                carry = prod.elems[i+j] / 10;
                prod.elems[i+j] = prod.elems[i+j] % 10;
                
            }
            
            prod.elems[i+M] = carry;
            
        }
        
        return prod;
    }
    
};


int main() {

    BigInteger a(string("99")), b(string("99")), c;
    
    c = a * b;
  
    for (auto iter = c.elems.rbegin(); iter != c.elems.rend(); ++iter) {
        cout << (*iter);
    }
    cout << endl;

}



























