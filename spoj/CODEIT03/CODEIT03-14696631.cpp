#include <iostream>
using namespace std;
/*
int cen_offc (int year) {
	int first2dig = (year - year%100)/100;
	int cen = first2dig;
	cen = first2dig-first2dig%4 + 4;
	cen -= 1;
	cen -= first2dig;
	cen *= 2;
	return cen;
}
int year_offc (int year) {
    int last2dig = year%100;
    int ans = (last2dig + (last2dig/4))%7;
    if (year % 400 == 0) ans -= 1;
    else if (year % 100 == 0) ;
    else if (year % 4 == 0) ans -= 1;

    return ans;
}
int months[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
int days[7] = {0,1,2,3,4,5,6};
*/
//sakamoto's algo
int wikipedia (int y, int m, int d) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
string day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main() {
	int date,month,year,t,cen_off,mon_off,date_off,year_off;
	cin>>t;
	while (t--) {
		cin>>date>>month>>year;
        /*
		cen_off = cen_offc(year);
		//cout<<cen_off<<" ";

		year_off = year_offc(year);
		//cout<<year_off<<" ";

		mon_off = months[month-1];
		date_off = days[date%7];

        //cout<<mon_off<<" "<<date_off<<"\n";
		int ans = cen_off + year_off + mon_off + date_off;
		cout<<day[ans%7]<<"\n";
		*/
		cout<<day[wikipedia(year,month,date)]<<"\n";
	}
	return 0;
}
