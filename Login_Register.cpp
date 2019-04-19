#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string name, pass, auxN, auxP;
char rasp;
bool regist = false, login = false;

int main() {

rasp1:
	system("cls");
	cout << "> L (pentru a te loga)\n";
	cout << "> R (pentru a te inregistra)\n";

	cout << "Ce vrei sa faci?\n_> ";
	cin >> rasp;

	switch (rasp) {
	case 'L':
	case 'l':
		login = true;
		break;

	case 'R':
	case 'r':
		system("cls");
		regist = true;
		break;

	default:
		cout << "Nu ai introdus informatii valide! te rugam sa reincerci.\n";
		system("pause");
		goto rasp1;
	}
regist:
	if (regist == true) {
		system("cls");
		cout << "Pentru a te inregistra...\n";
		cout << "Intrudu numele: ";
		cin >> name;
		cout << "Intrudu parola: ";
		cin >> pass;
		ofstream out("password.txt");
		out << name << "\n" << pass;
		system("cls");
		cout << "Te-ai inregistrat cu succes!\n> nume: " << name << "\n> parola: " << pass;
	}
login:
	if (login == true) {
		ifstream out("password.txt");
		if (!out) {
			cout << "Nu exista nici-un cont pe acest device! te rugam sa te inregistrezi\n";
			system("pause");
			regist = true;
			login = false;
			goto regist;
		}
		else
			system("cls");
			cout << "Pentru a te loga...\n";
			cout << "Intrudu numele: ";
			cin >> name;
			cout << "Intrudu parola: ";
			cin >> pass;
			ifstream in("password.txt");
			getline(in, auxN);
			getline(in, auxP);
			getline(in, auxP);

			if (auxP == pass && auxN == name) {
				system("cls");
				cout << "Te-ai logat cu succes!\n> nume: " << name << "\n> parola: " << pass;
			}
			else {
				cout << "Parola sau numele introduse nu sunt corecte! te rugam sa le reintroduci." << endl;
				system("pause");
				system("cls");
				goto login;
		}
	}
	cout << endl << endl;
	system("pause");
	return 0;
}