#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int toggleBit(int n, int pos)
{
	return (n xor (1 << pos));
}

int swapNumbers(int n)
{
	int firstBits = n >> 4;

	int lastBits = n & 0b00001111;

	return (lastBits << 4) | firstBits;
}

int main()
{
	unsigned char encryptedMessage[16]{
		0b10010110, 0b11110111, 0b01010110, 0b00000001,
		0b00010111, 0b00100110, 0b01010111, 0b00000001,
		0b00010111, 0b01110110, 0b01010111, 0b00110110,
		0b11110111, 0b11010111, 0b01010111, 0b00000011};

	for (int i = 0; i < sizeof(encryptedMessage); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			encryptedMessage[i] = toggleBit(encryptedMessage[i], j);
		}

		encryptedMessage[i] = swapNumbers(encryptedMessage[i]);

		cout << encryptedMessage[i];
	}

	return 0;
}
