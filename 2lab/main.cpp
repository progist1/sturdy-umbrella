#include <iostream>
#include <string>
#include <fstream>
#include "class.h"

using namespace std;

int main()
{

	Book b1;
	cout << b1.getnamebook() << "   " << b1.getcreator() << "   " << b1.getyear() << endl << endl;

	Book b2 ("The Engineers and the Price System" , "Thorstein Bunde Veblen" , 1921);
	Book b3 ("The Theory of Leisure Class" , "Thorstein Bunde Veblen" , 1899);

	b1.setnamebook("Harry Potter and the Methods of Rationality");
	b1.setcreator("Eliezer S. Yudkowsky");
	b1.setyear(2015);

	cout << b1.getnamebook() << "   " << b1.getcreator() << "   " << b1.getyear() << endl;
	cout << b2.getnamebook() << "   " << b2.getcreator() << "   " << b2.getyear() << endl;
	cout << b3.getnamebook() << "   " << b3.getcreator() << "   " << b3.getyear() << endl;
	
	Book lib[3];

	string sbuf;
	int ybuf;

	/*for (int i = 0; i<3; i++)
	

		cout << "enter name book ";
		cin >> sbuf;
		lib[i].setnamebook(sbuf);

		cout << "enter name creator ";
		cin >> sbuf;
		lib[i].setcreator(sbuf);

		cout << "enter year of writing ";
		cin >> ybuf;
		lib[i].setyear(ybuf);

	}


	for (int i = 0; i<3; i++)
	{

		cout << lib[i].getnamebook() << "  " << lib[i].getcreator() << "  " << lib[i].getyear() << endl;

	}*/


	int j = 1;

	while (j)
	{


		cout << "Menu"<< endl;
		cout << "1.Read"<< endl;
		cout << "2.View"<< endl;
		cout << "3.Edit"<< endl;
		cout << "4.Oldest book"<< endl;
		cout << "5.Saving in new file "<< endl;
		cout << "6.all_edit" << endl;
		cout << "7.Exit"<< endl;
		cout << "enter a number to continue " << endl;

		int i = 0;

		cin >> i;

		cout << endl;

		switch ( i ) {

			case 1: {
				//read(lib)

				ifstream read_stream;
				string file;
				cout << "Name file: ";
				cin >> file;
				file = file + ".txt";
				read_stream.open(file);

				string sbuf;
				int ybuf;

				if (read_stream) {

					for (int i = 0; i < 3; i++) {

						read_stream >> sbuf;
						lib[i].setnamebook(sbuf);

						read_stream >> sbuf;
						lib[i].setcreator(sbuf);

						read_stream >> ybuf;
						lib[i].setyear(ybuf);

					}
					read_stream.close();
				} else
					cout << "No file!" << endl;

				cout << endl;
				break;
			}

			case 2:
			{
				//view

				for (int i = 0; i<3; i++)
					cout << lib[i].getnamebook() << "  " << lib[i].getcreator() << "  " << lib[i].getyear() << endl;

				cout << endl;
				break;
			}

			case 3: {
				//edit
				
				int row = 0;

				cout << "Select a row to edit - ";
				cin >> row;
				row = row - 1;

				cout << "Book title - ";
				cin >> sbuf;
				lib[row].setnamebook(sbuf);

				cout << "Workbook author - ";
				cin >> sbuf;
				lib[row].setcreator(sbuf);

				cout << "Publication date - ";
				cin >> ybuf;
				lib[row].setyear(ybuf);

				cout << endl;
				break;
			}

			case 4:
			 {
				//old_book

				int t = 9999;
				int num = 0;

				for (int i=0; i<3; i++)
				{

					if (lib[i].getyear() < t)
					{

						t = lib[i].getyear();
						num = i;

					}

				}

				cout << "The old edition - " << lib[num].getnamebook() << "  ";
				cout << lib[num].getcreator() << "  " << lib[num].getyear() << endl;

				cout << endl;
				break;
			  }

			case 5:
			{
				//save

				string file_name;
				cout << "Save as.. ";
				cin >> file_name;
				file_name = "./" + file_name + ".txt";

				ofstream write_stream;
				write_stream.open(file_name);

				for (int i=0; i<3; i++)
				{
					string temp;
					int t;
					temp = lib[i].getnamebook();
					write_stream << temp << " ";
					temp = lib[i].getcreator();
					write_stream << temp << " ";
					t = lib[i].getyear();
					write_stream << t << endl;

				}
				write_stream.close();

				cout << endl;
				break;
			}

			case 6:
			{
					for (int i = 0; i<3; i++)
					{

						cout << "enter name book ";
						cin >> sbuf;
						lib[i].setnamebook(sbuf);

						cout << "enter name creator ";
						cin >> sbuf;
						lib[i].setcreator(sbuf);

						cout << "enter year of writing ";
						cin >> ybuf;
						lib[i].setyear(ybuf);
					}
			
			break;
			}


			case 7:

				j = 0;
				break;

			

			default:
			{
				cout << "doh"<< endl;
				cout << endl;
				break;
			}

		}
	}


	return 0;
}
