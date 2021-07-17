/*
The list of Regional Transport Offices and assigned codes for vehicle registration for the states Tripura(TR) and Mizoram(MZ) are given below. Write program that reads the vehicle number as input and store it in a string type. Extract the state code from vehicle number and identify the state it belongs to and Extract the district code and check which district it belongs to also extract the 4 digit vehicle number and store it into an integer array and pass it as a parameter to function that sums all the four digits and returns the value.





Input format
XXYYZZABCD (String)

Where XX is a state code. YY is a district code ABCD is the vehicle number.



Output format
State, District and sum as shown in sample output

Code constraints
State code - TR or MZ in upper case

District Code - 01 to 08

Sample testcases
Input 1
TR01BR2348
Output 1
State : Tripura
District : Agartala
Sum : 17
Input 2
MZ01BR2348
Output 2
State : Mizoram
District : Aizawl
Sum : 17*/

// You are using GCC

#include <bits/stdc++.h>

#include <tr1/unordered_map>
using namespace std;

int main() {
    tr1::unordered_map<string, string> mt;
    tr1::unordered_map<string, string> mm;

    mt["01"] = "Agartala";
    mt["02"] = "Kailasahar";
    mt["03"] = "Udaipur";
    mt["04"] = "Ambassa";
    mt["05"] = "Dharmnagar";
    mt["06"] = "Khowai";
    mt["07"] = "Sepahijala";
    mt["08"] = "Santirbazar";

    mm["01"] = "Aizawl";
    mm["02"] = "Lunglei";
    mm["03"] = "Saiha";
    mm["04"] = "Champhai";
    mm["05"] = "Kolasib";
    mm["06"] = "Serchhip";
    mm["07"] = "Lawngtlai";
    mm["08"] = "Mamit";

    string s;
    cin >> s;
    string state = s.substr(0, 2) == "TR" ? "Tripura" : "Mizoram";
    string district;
    if (state == "Mizoram")
        district = mm[s.substr(2, 2)];
    else
        district = mt[s.substr(2, 2)];
    string num = s.substr(s.length() - 4, 4);
    int sum = 0;
    for (int i = 6; i < 10; i++) sum += (s[i] - '0');
    cout << "State : " << state << endl;
    cout << "District : " << district << endl;
    cout << "Sum : " << sum;
}
