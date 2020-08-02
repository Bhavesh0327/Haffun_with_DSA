#include <iostream>
#include<math.h>
using namespace std;

/*Start from the fact that hexadecimal 0xf covers exactly four bits.
 There are four nibbles in a 16-bit number. 
 The masks for the nibbles are 0xf000, 0xf00, 0xf0, and 0xf.
 Then start masking, shifting and bitwise OR-ing.
*/

int main() {
	int t;
	cin >> t;
	while(t--){
	    long long int v;
	    cin >> v;
	    cout << (((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4)) << endl;

	}
	return 0;
}