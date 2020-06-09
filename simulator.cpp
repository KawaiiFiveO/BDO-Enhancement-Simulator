using namespace std;
#include <iostream>
#include <cstdlib>
#include <time.h>

int stop = 0;
int failstack = 0;
string crons = "No";
int times = 1;
string translate = "PEN";
double start = .3;
int multiplier = 6;
int acc = 0;

void setFS();
void setType();
void setCrons();
void setTimes();
void runSim();
void runSimAcc();
void quit();

int main() {
	srand(time(NULL));
    while (stop == 0) {
	    system("CLS");
		int choice;
		cout << "*** Black Desert Online Enhancement Simulator v2.2 by Kat ***\n\n";
		cout << "--------Status--------\nFailstacks: " << failstack << "\nEnhancement type: " << translate << "\nUsing Cron Stones: " << crons << "\nNumber of attempts: " << times << "\n----------------------\n\n";
		cout << "What would you like to do?\n1: Set number of failstacks\n2: Set enhancement type\n3: Change Cron Stone setting\n4: Set number of attempts\n5: Start simulation\n6: Exit\n\nSelect: ";
		cin >> choice;
		if (choice == 1)
			setFS();
		if (choice == 2)
			setType();
		if (choice == 3)
			setCrons();
		if (choice == 4)
			setTimes();
		if (choice == 5)
			if (acc == 0)
				runSim();
			else
				runSimAcc();
		if (choice == 6)
			quit();
    }
    return 0;
}

void setFS() {
    cout << "Failstacks: ";
    cin >> failstack;
    if (failstack < 0) {
        failstack = 0;
    }
}

void setType() {
	system("CLS");
	int type = 0;
	cout << "Enhancement Type\n\n1: TRI\n2: TET\n3: PEN\n4: +15\n5: TRI Blackstar\n6: TET Blackstar\n7: PEN Blackstar\n8: DUO Accessory\n9: TRI Accessory\n10: TET Accessory\n11: PEN Accessory\n\nSelect: ";
    cin >> type;
        if (type == 1) {
			translate = "TRI";
            start = 6.25;
            multiplier = 4;
			acc = 0;
        } else if (type == 2) {
			translate = "TET";
            start = 2;
            multiplier = 5;
			acc = 0;
        } else if (type == 3) {
			translate = "PEN";
            start = .3;
            multiplier = 6;
			acc = 0;
        } else if (type == 4) {
			translate = "+15";
            start = 2;
            multiplier = 1;
			acc = 0;
        } else if (type == 5) {
			translate = "TRI BS";
            start = 3.4;
            multiplier = 4;
			acc = 0;
        } else if (type == 6) {
			translate = "TET BS";
            start = .51;
            multiplier = 5;
			acc = 0;
        } else if (type == 7) {
			translate = "PEN BS";
            start = .2;
            multiplier = 6;
			acc = 0;
        } else if (type == 8) {
			translate = "DUO Acc";
            start = 10;
            multiplier = 1;
			acc = 1;
        } else if (type == 9) {
			translate = "TRI Acc";
            start = 7.5;
            multiplier = 1;
			acc = 2;
        } else if (type == 10) {
			translate = "TET Acc";
            start = 2.5;
            multiplier = 1;
			acc = 3;
        } else if (type == 11) {
			translate = "PEN Acc";
            start = .5;
            multiplier = 1;
			acc = 4;
        } else {
			translate = "TRI";
            start = 6.25;
            multiplier = 4;
			acc = 0;
        }
}

void setCrons() {
	if (crons != "No") {
		crons = "No";
	}
	else {
		crons = "Yes";
	}
}

void setTimes() {
    cout << "Attempts: ";
    cin >> times;
    if (times < 1) {
        times = 1;
    }
}

void runSim() {
	    system("CLS");
		cout << "Outcome of enhancing " << times << " times:\n\n";
        double test = 0;
        int success = 0;
		double plus = 0;
		double temp = start;
		int cronsave = multiplier;

        if (crons == "Yes") {
            multiplier = 0;
        }

        plus = start / 10;
        double first = start + (failstack * plus);
		if (first > 90)
			first = 90;
        temp = 1 - (start / 100);
        plus = plus / 100;
        double chance = 0;
        temp = temp - (failstack * plus);
        double recursive = 1;

        for (int i = 0; i < times; i++) {
			if (temp < .1) {
				temp = .1;
			}
            recursive = recursive * temp;
            test = ((double) rand() / (RAND_MAX));
            if (test > temp) {
                success++;
                cout << "Enhancement Success! (+" << failstack << " " << 100 * (1 - temp) << "%)\n";
            } else if (crons == "Yes") {
                cout << "Enhancement Failed, Item Protected\n";
            } else {
                cout << "Enhancement Failed, Enhancement Level Drop (+" << failstack << " " << 100 * (1 - temp) << "%)\n";
            }
			if (temp <= .3) {
				temp = temp - (plus / 5 * multiplier);
			} else {
				temp = temp - (plus * multiplier);
			}
            failstack = failstack + multiplier;
        }
        multiplier = cronsave;
        chance = temp;
		if (chance < .1)
			chance = .1;
        recursive = (1 - recursive) * 100;
        chance = (1 - chance) * 100;
        if (translate == "+15" && crons == "Yes")
			cout << "You know you can't use crons for a +15, dummy...\n";
        cout << "\nYou succeeded " << success << " time(s) out of " << times << ".\n";
        cout << failstack << " failstacks at end\n";
        cout << first << "% chance to succeed on first try\n";
        cout << recursive << "% chance to succeed at least once\n";
        cout << chance << "% chance to succeed on the next attempt\n";
        system("pause");
}

void runSimAcc() {
	    system("CLS");
		cout << "Outcome of enhancing " << times << " times:\n\n";
        double test = 0;
		double downgrade = 0;
        int success = 0;
		double plus = 0;
		double temp = start;
		int cronsave = multiplier;

        if (crons == "Yes") {
            multiplier = 0;
        }

        plus = start / 10;
        double first = start + (failstack * plus);
		if (first > 90)
			first = 90;
        temp = 1 - (start / 100);
        plus = plus / 100;
        double chance = 0;
        temp = temp - (failstack * plus);
        double recursive = 1;

        for (int i = 0; i < times; i++) {
			if (temp < .1) {
				temp = .1;
			}
            recursive = recursive * temp;
            test = ((double) rand() / (RAND_MAX));
			downgrade = ((double) rand() / (RAND_MAX));
            if (test > temp) {
                success++;
                cout << "Enhancement Success! (+" << failstack << " " << 100 * (1 - temp) << "%)\n";
            } else if (crons == "Yes") {
                if (downgrade < .3) {
					cout << "Enhancement Failed, Enhancement Level Drop\n";
				} else {
					cout << "Enhancement Failed, Item Protected\n";
				}
            } else {
                cout << "Enhancement Failed, Item Destroyed (+" << failstack << " " << 100 * (1 - temp) << "%)\n";
            }
			if (acc == 1 && temp <= .5) {
				temp = temp - (plus / 5 * multiplier);
			} else if (acc == 2 && temp <= .6) {
				temp = temp - (plus / 5 * multiplier);
			} else if (acc == 3 && temp <= .7) {
				temp = temp - (plus / 5 * multiplier);
			} else {
				temp = temp - (plus * multiplier);
			}
            failstack = failstack + multiplier;
        }
        multiplier = cronsave;
        chance = temp;
		if (chance < .1)
			chance = .1;
        recursive = (1 - recursive) * 100;
        chance = (1 - chance) * 100;
        cout << "\nYou succeeded " << success << " time(s) out of " << times << ".\n";
        cout << failstack << " failstacks at end\n";
        cout << first << "% chance to succeed on first try\n";
        cout << recursive << "% chance to succeed at least once\n";
        cout << chance << "% chance to succeed on the next attempt\n";
        system("pause");
}

void quit() {
	stop = 1;
}