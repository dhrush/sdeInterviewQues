#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string validateIPv4(string ip)
{
    regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0- 9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
    if (regex_match(ip, ipv4))
        return "IPv4";
    else
        return "False";
}

int main()
{
    // your code goes here
    string ip = "172.16.25.234";
    string ans = validateIPv4(ip);
    cout << ans << endl;
    return 0;
}