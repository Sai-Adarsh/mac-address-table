#ifndef SWITCH_LIBRARY_H
#define SWITCH_LIBRARY_H

#include <iostream>
#include <map>

using namespace std;

struct Port
{
    string l2MacAddress;
    string l3IpAddress;
    string fAPortNo;
};

struct MacTableValue
{
    string l2MacAddress;
    string l3IpAddress;
    string fAPortNo;

    MacTableValue() {}

    void setValues(const string &mac, const string &ip, const string &port);
};

struct MacAddressTable
{
    map<string, MacTableValue> addressTable;
};

class Switch
{
    Port *lPort;

public:
    Switch(string aInMacAddress, string aInIpAddress, string aInPortNo);
    ~Switch();
    Port *getPort();
};

void send(MacAddressTable &aInMac, Switch *aInFrom, Switch *aInTo);

#endif // SWITCH_LIBRARY_H