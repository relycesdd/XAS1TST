#include <iostream>
using namespace std;
#include <WORKER.h>

int main()
{
	ifstream in = ifstream(WORKER.h);
	if (!in) return 1;
	WORKER gr[10];
	int n - 0;
	while (in >> gr[n])n++;
	for (Man m : gr)
		cout << m << "\n";

}