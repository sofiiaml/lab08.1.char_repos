#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s) 
{
	int k = 0,
		pos = 0; 
	char* t;
	while (t = strchr(s + pos, '+')) 
	{
		pos = t - s + 1; 
		k++;
	}
	pos = 0;
	while (t = strchr(s + pos, '-')) 
	{
		pos = t - s + 1;
		
			k++;
	}
	pos = 0;
	while (t = strchr(s + pos, '=')) 
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}
char* Change(char* s) // s = вказівник на початок рядка
{
	char* t = new char[strlen(s)];
	char* p;// p = вказівник на '+'
	char* m;// m =
	char* e;// e =
	int pos1 = 0, // pos1 = позиція початку пошуку
		pos2 = 0;
	*t = 0;
	while (true) 
	{
		if (pos1 == strlen(s))
			break;
		
		p = strchr(s + pos1, '+');
		m = strchr(s + pos1, '-');
		e = strchr(s + pos1, '=');
		if (p || m || e) {
			if (abs(p - s) < abs(m - s) && abs(p - s) < abs(e - s)) {
				if (s[p - s + 1] == '+')
				{
					pos2 = p - s + 2; 
					strncat(t, s + pos1, pos2 - pos1 - 2);
					strcat(t, "***");
					pos1 = pos2;
				}
				else
				{
					pos2 = p - s + 1; 
					strncat(t, s + pos1, pos2 - pos1);
					pos1 = pos2;
				}
			}
			else  if (abs(m - s) < abs(e - s)) {
				if (s[m - s + 1] == '-')
				{
					pos2 = m - s + 2; 
					strncat(t, s + pos1, pos2 - pos1 - 2);
					strcat(t, "***");
					pos1 = pos2;
				}
				else
				{
					pos2 = m - s + 1; 
					strncat(t, s + pos1, pos2 - pos1);
					pos1 = pos2;
				}
			}
			else {
				if (s[e - s + 1] == '=')
				{
					pos2 = e - s + 2;
					strncat(t, s + pos1, pos2 - pos1 - 2);
					strcat(t, "***");
					pos1 = pos2;
				}
				else
				{
					pos2 = e - s + 1; 
					strncat(t, s + pos1, pos2 - pos1);
					pos1 = pos2;
				}

			}
		}
		else {
			pos2 = pos1 + 1;
			strncat(t, s + pos1, pos2 - pos1);
			pos1 = pos2;
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];
		cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " elements of +,- or =" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}