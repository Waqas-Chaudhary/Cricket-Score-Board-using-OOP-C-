#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
using namespace std;
int totalovers, bat1, bat2, bat3, bat4;	bool check1, check2;

class batsman
{
public:
	int scored, ballsfaced, missedballs;
	batsman()
	{
		scored = 0; ballsfaced = 0; missedballs = 0;
	}
	void add_scored(int s)
	{
		scored = scored + s; 		ballsfaced = ballsfaced + 1;
	}
	void add_missedballs()
	{
		missedballs = missedballs + 1; 		ballsfaced = ballsfaced + 1;
	}
};
class bowler
{
public:
	int  score, overs, wickets, dotballs;
	bowler()
	{
		score = 0; overs = 0; wickets = 0; dotballs = 0;
	}
	void add_score(int s)
	{
		score = score + s;
	}
	void add_overs()
	{
		overs = overs + 1;
	}
	void add_wickets()
	{
		wickets = wickets + 1;
	}
	void add_dotballs()
	{
		dotballs = dotballs + 1;
	}
};
class player : public batsman, public bowler
{
public:
	string name;
	player()
	{
		name = "N / A";
	}
};

class team
{
public:
	string team_name;
	int total, extra, wicket;
	player p[5];
	bool out[5];
	team()
	{
		team_name = "\0";
		total = 0;
		extra = 0;
		wicket = 0;
		for (int i = 0; i < 5; i++)
		{
			out[i] = false;
		}
	}
};
class match : public team
{
public:
	player frt;
	player snd;
	player frt2;
	player snd2;
	player bowler;
	team t1;
	team t2;
	bool toss;
	void swap1()
	{
		player temp;
		temp = frt;
		frt = snd;
		snd = temp;
		t1.p[bat1] = frt;
		t1.p[bat2] = snd;
		cout << "\nStriker Changed !!!!" << endl;
		cout << "Current Striker : " << frt.name << endl;
		cout << "Current Non-Striker : " << snd.name << endl;
		system("pause");
		system("cls");
	}
	void swap2()
	{
		player temp;
		temp = frt2;
		frt2 = snd2;
		snd2 = temp;
		t2.p[bat3] = frt2;
		t2.p[bat4] = snd2;
		cout << "\nStriker Changed !!!!" << endl;
		cout << "Current Striker : " << frt2.name << endl;
		cout << "Current Non-Striker : " << snd2.name << endl;
		system("pause");
		system("cls");
	}
	void setTeamNames()
	{
		system("cls");
		ifstream pic;
		string st;
		pic.open("TeamNames.txt");
		while (getline(pic, st))
		{
			cout << st << endl;
		}
		cout << "Enter 1st Team Name : ";
		getline(cin, t1.team_name);
		cout << "Enter 2nd Team Name : ";
		getline(cin, t2.team_name);
		cout << "Team Names settled!\n";
		system("pause");
		system("cls");
	}
	void set_toss()
	{
		system("cls");
		ifstream pic;
		string st;
		pic.open("Toss.txt");
		while (getline(pic, st))
		{
			cout << st << endl;
		}
	here:
		int temp;
		cout << "---Who won the Toss---\n";
		cout << "Press 1 for " << t1.team_name << "\nPress 2 for " << t2.team_name << endl;
		cin >> temp;
		if (cin.fail())
		{
			goto here;
		}
		if (temp == 1)
		{
			toss = true;
		}
		else if (temp == 2)
		{
			toss = false;
		}
		else
		{
			cout << "Invalid Input! Enter Again...... \n" << endl;
			goto here;
		}
		system("pause");
		system("cls");
	}
	void set_names()
	{
		system("CLS");
		ifstream pic;
		string st;
		pic.open("PlayersDataLogo.txt");
		while (getline(pic, st))
		{
			cout << st << endl;
		}
		cout << "Enter Player Names for team " << t1.team_name << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < 5; i++)
		{
			cout << "Player No." << i + 1 << "=>";
			getline(cin, t1.p[i].name);
			//cin.ignore(1, '\n');
		}
		system("pause");
		system("cls");
		{
			ifstream pic;
			string st;
			pic.open("PlayersDataLogo.txt");
			while (getline(pic, st))
			{
				cout << st << endl;
			}}
		cout << "Enter Player Names for team " << t2.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Player No." << i + 1 << "=>";
			getline(cin, t2.p[i].name);
		}
		cout << "Player Names Settled\n";
		system("pause");
		system("cls");
	}
	void show_players1()
	{
		cout << "Player Names for team " << t1.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Player No." << i + 1 << "=>" << t1.p[i].name << endl;
		}
	}
	void show_playersNotOut1()
	{
		cout << "Player not out of team " << t1.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			if (t1.out[i] != true)
			{
				if (snd.name != t1.p[i].name)
				{
					cout << "Player No." << i + 1 << "=>" << t1.p[i].name << endl;
				}
			}
		}
	}
	void show_players2()
	{
		cout << "Player Names for team " << t2.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Player No." << i + 1 << "=>" << t2.p[i].name << endl;
		}
	}
	void show_playersNotOut2()
	{
		cout << "Player not Out of team " << t2.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			if (t2.out[i] != true)
			{
				if (snd.name != t2.p[i].name)
				{
					cout << "Player No." << i + 1 << "=>" << t2.p[i].name << endl;
				}
			}
		}
	}
	void next_batsman1()
	{
	here:
		/*t1.p[bat1] = frt;
		t1.p[bat2] = snd;*/
		//system("cls");
		show_players1();
		int i, j;
		cout << "Enter Striker number : "; cin >> i;
		if (cin.fail())
		{
			goto here;
		}
		cout << "Enter Non-Striker number : "; cin >> j;
		if (cin.fail())
		{
			goto here;
		}
		frt = t1.p[i - 1];
		snd = t1.p[j - 1];
		bat1 = i - 1;
		bat2 = j - 1;

		cout << "Striker : " << frt.name << endl;
		cout << "Non-striker : " << snd.name << endl;
	}
	void changeStriker1()
	{
	here:
		t1.p[bat1] = frt;
		t1.p[bat2] = snd;
		//system("cls");
		show_playersNotOut1();
		int i, j;
		cout << "Enter Striker number : "; cin >> i;
		if (cin.fail())
		{
			goto here;
		}
		frt = t1.p[i - 1];
		bat1 = i - 1;
		cout << "Striker : " << frt.name << endl;
		cout << "Non-striker : " << snd.name << endl;
	}
	void changeStriker2()
	{
	here:
		t2.p[bat3] = frt2;
		t2.p[bat4] = snd2;
		//system("cls");
		show_playersNotOut2();
		int i, j;
		cout << "Enter Striker number : "; cin >> i;
		if (cin.fail())
		{
			goto here;
		}
		frt2 = t2.p[i - 1];
		bat3 = i - 1;
		cout << "Striker : " << frt2.name << endl;
		cout << "Non-striker : " << snd2.name << endl;
	}
	void next_batsman2()
	{

	here:

		//system("cls");
		show_players2();
		int i, j;
		cout << "Enter Striker number : ";
		cin >> i;
		if (cin.fail())
		{
			goto here;
		}
		cout << "Enter Non-Striker number : ";
		cin >> j;
	here2:
		if (cin.fail())
		{
			goto here2;
		}
		frt2 = t2.p[i - 1];
		snd2 = t2.p[j - 1];
		bat3 = i - 1;
		bat4 = j - 1;
		t2.p[bat3] = frt2;
		t2.p[bat4] = snd2;
		cout << "Striker : " << frt2.name << endl;
		cout << "Non-striker : " << snd2.name << endl;
	}
	void next_bowler1()
	{
		show_players1();
		int i;
		cout << "Enter Bowler No. : ";
		cin >> i;
		bowler = t1.p[i - 1];
		cout << endl << "Current Bowler : " << bowler.name << endl;
	}
	void next_bowler2()
	{
		show_players2();
		int i;
		cout << endl << endl << "Enter Bowler No. : ";
		cin >> i;
		bowler = t2.p[i - 1];
		cout << endl << "Current Bowler : " << bowler.name << endl;
	}
	void inning1()
	{
		next_batsman1();
		next_bowler2();
		int balls = 0, test = 0; int i = 0;
	here1:
		while (test < totalovers)
		{
			while (balls < 6)
			{
				cout << "--------------------------\n";
				cout << "---Choose from below  ---" << endl;
				cout << "---Enter 0 : Dot ball ---" << endl;
				cout << "---Enter 1 : Single   ---" << endl;
				cout << "---Enter 2 : Double   ---" << endl;
				cout << "---Enter 3 : Triple   ---" << endl;
				cout << "---Enter 4 : Four     ---" << endl;
				cout << "---Enter 5 : Wide+Four---" << endl;
				cout << "---Enter 6 : Six      ---" << endl;
				cout << "---Enter 7 : Wide/No-Ball" << endl;
				cout << "---Enter 8 : Wicket   ---" << endl;
				cout << "--------------------------\n";
				int temp;
			here11:
				cin >> temp;
				if (cin.fail())
				{
					cin.clear();
					cout << "Input Failure\ntry again\n";
					cin.ignore(1000, '\n');
					goto here11;
				}
				switch (temp)
				{
				case 0:
				{
					t1.total = t1.total + 0;
					frt.add_missedballs();
					bowler.add_dotballs();
					balls++;
					break;
				}
				case 1:
				{
					t1.total = t1.total + 1;
					frt.add_scored(1);
					bowler.add_score(1);
					balls++;
					swap1();
					break;
				}
				case 2:
				{
					t1.total = t1.total + 2;
					frt.add_scored(2);
					bowler.add_score(2);
					balls++;
					break;
				}
				case 3:
				{
					t1.total = t1.total + 3;
					frt.add_scored(3);
					bowler.add_score(3);
					balls++;
					swap1();
					break;
				}
				case 4:
				{
					t1.total = t1.total + 4;
					frt.add_scored(4);
					bowler.add_score(4);
					balls++;
					break;
				}
				case 5:
				{
					t1.total = t1.total + 5;
					//t1.extra = t1.extra + 5;
					bowler.add_score(5);
					break;
				}
				case 6:
				{
					t1.total = t1.total + 6;
					frt.add_scored(6);
					bowler.add_score(6);
					balls++;
					break;
				}
				case 7:
				{
					t1.total = t1.total + 1;
					//t1.extra = t1.extra + 1;
					bowler.add_score(1);
					break;
				}
				case 8:
				{
					bowler.add_wickets();
					t1.out[bat1] = true;
					i++;
					t1.wicket = t1.wicket + 1;
					if (t1.wicket > 3) { cout << "Wickets reached!....\n"; Sleep(2000); return; }
					changeStriker1();
					break;
				}
				default:
				{
					cout << "Wrong Input......\nPlease Select from the Menu......" << endl;
					system("pause");
					system("cls");
					goto here1;
				}
				}
				//t1.total = t1.total + t1.extra;
				system("cls");
				cout << "\nBowler : " << bowler.name << " Score : " << bowler.score << " Wickets : " << bowler.wickets << " Over : " << bowler.overs << " Ball : " << balls << endl;
				cout << "\nStriker : " << frt.name << " Scored : " << frt.scored << " Missed Balls : " << frt.missedballs << " Balls faced :  " << frt.ballsfaced << endl;
				cout << "\nNon_Striker : " << snd.name << " Scored : " << snd.scored << " Missed Balls : " << snd.missedballs << " Balls Faced : " << snd.ballsfaced << endl;
				cout << "Team " << t1.team_name << " Total : " << t1.total << " Wickets : " << t1.wicket << endl;
			}
			test++;
			bowler.add_overs();
			system("cls");
			cout << "\nBowler : " << bowler.name << " Score : " << bowler.score << " Wickets got " << bowler.wickets << " Over : " << bowler.overs << " Balls : " << balls << endl;
			cout << "\nStriker : " << frt.name << " Scored : " << frt.scored << " Missed Balls : " << frt.missedballs << " Balls Faced : " << frt.ballsfaced << endl;
			cout << "\nNon_striker : " << snd.name << " Scored : " << snd.scored << " Missed Balls : " << snd.missedballs << " Balls Faced : " << snd.ballsfaced << endl;
			cout << "\nOver Reached!!!" << endl;
			cout << "Team " << t1.team_name << " Total : " << t1.total << " Wickets (Out) : " << t1.wicket << endl;
			t1.p[bat1] = frt;
			t1.p[bat2] = snd;
			system("pause");
			system("cls");
			if (t1.total > t2.total && check2 == true)
			{
				getWinner();
				return;
			}
			if (test < totalovers)
			{
				next_bowler2();
			}
			else
			{
				cout << "No more Overs\n";
				Sleep(2000);
				return;
			}
			swap1();
			balls = 0;
		}
		check1 = true;
	}
	void inning2()
	{
		int i = 1;

		next_batsman2();
		next_bowler1();
		int balls = 0, test = 0;
	here1:
		while (test < totalovers)
		{

			while (balls < 6)
			{
				cout << "--------------------------\n";
				cout << "---Choose from below  ---" << endl;
				cout << "---Enter 0 : Dot ball ---" << endl;
				cout << "---Enter 1 : Single   ---" << endl;
				cout << "---Enter 2 : Double   ---" << endl;
				cout << "---Enter 3 : Triple   ---" << endl;
				cout << "---Enter 4 : Four     ---" << endl;
				cout << "---Enter 5 : Wide+Four---" << endl;
				cout << "---Enter 6 : Six      ---" << endl;
				cout << "---Enter 7 : Wide/No-Ball" << endl;
				cout << "---Enter 8 : Wicket   ---" << endl;
				cout << "--------------------------\n";
				int temp;
			here11:
				cin >> temp;
				if (cin.fail())
				{
					cin.clear();
					cout << "Input Failure\ntry again\n";
					cin.ignore(1000, '\n');
					goto here11;
				}
				switch (temp)
				{
				case 0:
				{
					t2.total = t2.total + 0;
					frt2.add_missedballs();
					bowler.add_dotballs();
					balls++;
					break;
				}
				case 1:
				{
					t2.total = t2.total + 1;
					frt2.add_scored(1);
					bowler.add_score(1);
					balls++;
					swap2();
					break;
				}
				case 2:
				{
					t2.total = t2.total + 2;
					frt2.add_scored(2);
					bowler.add_score(2);
					balls++;
					break;
				}
				case 3:
				{
					t2.total = t2.total + 3;
					frt2.add_scored(3);
					bowler.add_score(3);
					balls++;
					swap2();
					break;
				}
				case 4:
				{
					t2.total = t2.total + 4;
					frt2.add_scored(4);
					bowler.add_score(4);
					balls++;
					break;
				}
				case 5:
				{
					t2.total = t2.total + 5;
					//t2.extra = t2.extra + 5;
					bowler.add_score(5);
					break;
				}
				case 6:
				{
					t2.total = t2.total + 6;
					frt2.add_scored(6);
					bowler.add_score(6);
					balls++;
					break;
				}
				case 7:
				{
					t2.total = t2.total + 1;
					//t2.extra = t2.extra + 1;
					bowler.add_score(1);
					break;
				}
				case 8:
				{
					bowler.add_wickets();
					t2.out[bat3] = true;
					i++;
					t2.wicket = t2.wicket + 1;
					if (t2.wicket > 3) { cout << "Wickets reached!....\n"; Sleep(2000); return; }
					changeStriker2();
				}
				default:
				{
					cout << "Wrong Input......\nPlease Select from the Menu...... " << endl;
					system("pause");
					system("cls");
					goto here1;
				}
				}
				system("cls");
				cout << "\nBowler : " << bowler.name << " Score : " << bowler.score << " got Wickets : " << bowler.wickets << " Overs : " << bowler.overs << " Ball : " << balls << endl;
				cout << "\nStriker : " << frt2.name << " Scored : " << frt2.scored << " Missed Balls : " << frt2.missedballs << " Balls Faced : " << frt2.ballsfaced << endl;
				cout << "\nNon_Striker : " << snd2.name << " Scored : " << snd2.scored << " Missed Balls : " << snd2.missedballs << " Balls Faced : " << snd2.ballsfaced << endl;
				cout << "\nTeam " << t2.team_name << " Total : " << t2.total << " Wickets (out) : " << t2.wicket << endl;
			}
			test++;
			bowler.add_overs();
		hereee:
			system("cls");
			cout << "\nBowler : " << bowler.name << " Score : " << bowler.score << " got Wickets : " << bowler.wickets << " Overs : " << bowler.overs << " Balls : " << balls << endl;
			cout << "\nStriker : " << frt2.name << " Scored : " << frt2.scored << " Missed Balls : " << frt2.missedballs << " Balls Faced : " << frt2.ballsfaced << endl;
			cout << "\nNon_Striker : " << snd2.name << " Scored : " << snd2.scored << " Missed Balls : " << snd2.missedballs << " Balls Faced : " << snd2.ballsfaced << endl;
			cout << "\nTeam " << t2.team_name << " Total : " << t2.total << " Wickets (out) : " << t2.wicket << endl;
			cout << "\nOver Reached!!!" << endl;
			t2.p[bat3] = frt2;
			t2.p[bat4] = snd2;
			system("pause");
			system("cls");
			if (t2.total > t1.total && check1 == true)
			{
				getWinner();
				return;
			}
			if (test < totalovers)
			{
				next_bowler1();
			}
			else
			{
				cout << "No more Overs\n";
				return;
			}
			swap2();
			balls = 0;
		}
		check2 = true;
	}
	void getWinner()
	{
		if (t1.total < t2.total)
			cout << t2.team_name << " has won the match" << endl;
		else if (t1.total == t2.total)
			cout << "Match Draw!!!!\n";
		else
			cout << t1.team_name << " has won the match" << endl;
	}
	void whoWannaBatFirst()
	{
		while (1)
		{
		here:
			ifstream pic;
			string st;
			pic.open("Bat First.txt");
			while (getline(pic, st))
			{
				cout << st << endl;
			}

			int temp;
			cout << "Who wanna Bat First!!!\n";
			cout << "1-" << t1.team_name << endl;
			cout << "2-" << t2.team_name << endl;
			cout << "Enter index number : " << endl;
			cin >> temp;
			if (cin.fail())
			{
				cout << "Input Failure!!! Enter again!\n";
				goto here;
			}
			if (temp == 1)
			{
				toss = true;
				break;
			}
			else if (temp == 2)
			{
				toss = false;
				break;
			}
			else
			{
				cout << "Invalid Input! Enter again\n";
				Sleep(2000);
				system("cls");
			}
		}
	}
	void startMatch()
	{
		if (toss == true)
		{
			cout << t1.team_name << " is going to bat first" << endl;
			cout << "Innings 01\n";
			inning1();
			WriteBatingData1();
			cout << "Innings 02\n";
			inning2();
			WriteBatingData2();

		}
		else
		{
			cout << t2.team_name << " is going to bat first" << endl;
			cout << "Innings 01\n";
			inning2();
			WriteBatingData2();
			cout << "Innings 02\n";
			inning1();
			WriteBatingData1();
		}
	}
	void setOvers()
	{
	here:
		ifstream pic;
		string st;
		pic.open("Overs.txt");
		while (getline(pic, st))
		{
			cout << st << endl;
		}
		cout << "Enter Overs:" << endl;
		cin >> totalovers;
		if (cin.fail())
		{
			goto here;
		}
		cout << "Overs Settled\n";
		system("pause");
	}
	void showNotOut()
	{
		cout << "Player Names for team not out " << t1.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			if (out[i] != true)
			{
				cout << "Player No. " << i + 1 << t1.p[i].name << endl;
			}
		}
	}
	void showBatingData1()
	{
		cout << "Displaying Bating Data for Team " << t1.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Name : " << t1.p[i].name << " Scored : " << t1.p[i].scored << " Balls Played : " << t1.p[i].ballsfaced << " Missed Balls : " << t1.p[i].missedballs << endl;
		}
		cout << "Total Scores by Team : " << t1.total << endl;
	}
	void showBatingData2()
	{
		cout << "Displaying Bating Data for Team " << t2.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Name : " << t2.p[i].name << " Scored : " << t2.p[i].scored << " Balls Played : " << t2.p[i].ballsfaced << " Missed Balls : " << t2.p[i].missedballs << endl;
		}
		cout << "Total Scores by Team : " << t2.total << endl;
	}
	void WriteBatingData1()
	{
		ofstream t11;
		t11.open(t1.team_name + ".txt", ios::trunc);
		t11 << "Displaying Bating Data for Team " << t1.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			t11 << "Name : " << t1.p[i].name << " Scored : " << t1.p[i].scored << " Balls Played : " << t1.p[i].ballsfaced << " Missed Balls : " << t1.p[i].missedballs << endl;
		}
		t11 << "Total Scores by Team : " << t1.total << endl;
	}
	void WriteBatingData2()
	{
		ofstream t22;
		t22.open(t2.team_name + ".txt", ios::trunc);
		t22 << "Displaying Bating Data for Team " << t2.team_name << endl;
		for (int i = 0; i < 5; i++)
		{
			t22 << "Name : " << t2.p[i].name << " Scored : " << t2.p[i].scored << " Balls Played : " << t2.p[i].ballsfaced << " Missed Balls : " << t2.p[i].missedballs << endl;
		}
		t22 << "Total Scores by Team : " << t2.total << endl;
	}
};
int main()
{
	ifstream pic;
	string st;
	pic.open("Logo1.txt");
	while (getline(pic, st))
	{
		cout << st << endl;
	}
	system("pause");
	match m;
	m.setTeamNames();
	m.setOvers();
	m.set_toss();
	m.whoWannaBatFirst();
	m.set_names();
	m.startMatch();
	m.getWinner();
	cout << "\n\n";
	m.showBatingData1();
	cout << "\n\n";
	m.showBatingData2();
	return 0;
}
