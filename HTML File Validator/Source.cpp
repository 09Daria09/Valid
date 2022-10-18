#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string path;
	cout << "Specify the path to the file -> ";
	cin >> path;
	char t = '\0';
	bool a = true;
	ifstream in(path, ios::in);

	if (in)
	{
		while (!in.eof() && a)
		{
			in.get(t);
			if (t == '<')
			{
				in.seekg(1, ios::cur);
				while (!in.eof())
				{
					in.get(t);
					if (t == '>')
					{
						break;
					}
					else if (t == '<')
					{
						cout << "ERROR" << endl;
						a = false;
						break;
					}
				}
			}
			if (in.eof())
			{
				cout << "All good" << endl;
			}
		}
	}
	else
	{
		cout << "Could not open the file" << endl;
	}

	string str[20];
	string temp;
	int i = 0;
	fstream val(path, ios::in); 
	if (val)
	{
		while (!val.eof())
		{
			val >> temp;
			if (temp == "<html" || temp == "</html>" || temp == "<head>" || temp == "</head>" || temp == "<title>" || temp == "</title>" || temp == "<body>" || temp == "</body>")
			{
				str[i] = temp;
				i++;
			}
		}
	}
	else
	{
		cout << "Could not open the file" << endl;
	}
	for (int i = 0; i < 20; i++)
	{
		if (str[i] != "")
		{
			cout << str[i] << "\t";
		}
	}
	cout << endl;
	if (str[0] != "<html" && str[7] != "</html>")
	{
		cout << "Error. html" << endl;
	}
	else if (str[1] != "<head>" && str[4] != "</head>")
	{
		cout << "Error. head" << endl;
	}
	else if (str[2] != "<<title>" && str[3] != "</title>")
	{
		cout << "Error. title" << endl;
	}
	else if (str[5] != "<body>" && str[6] != "</body>")
	{
		cout << "Error. body" << endl;
	}
	else
	{
		cout << "All good ^)" << endl;
	}

}