#include <bits/stdc++.h>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds       

using namespace std;
int main() {
	string str;
	char text[100];
	char subtitle[100];

	str = "powershell.exe -command \"New-BurntToastNotification -AppLogo \"c:/washbasin.png\"";

	cout << "What do you want the toast to say? ";
	cin.getline(text, 100);

	str = str + " -Text '" + text + "'";
	cout << "What should the Subtitle be? ";

	cin.getline(subtitle, 100);
	if (strcmp(subtitle, "")) {
		str = str + ", '" + subtitle + "'";
	}
	int timer;
	cout << "How often? ";
	cin >> timer;
	str = str + "\"";
	int count = 0;
	system(str.c_str());
	while(true) {
		count++;
		for (int i=timer; i>0; --i) {
			std::this_thread::sleep_for (std::chrono::seconds(60)); //test comment
		}
		cout << "Toast Sent";
		system(str.c_str());
	}
	return 0;
}
