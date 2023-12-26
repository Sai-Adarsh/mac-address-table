#include "SwitchLibrary.h"

int main()
{
    MacAddressTable MacTable;
    Switch *MySwitch1 = new Switch("MAC-1", "10.1.1.2", "1");
    Switch *MySwitch2 = new Switch("MAC-2", "10.1.1.3", "2");
    Switch *MySwitch3 = new Switch("MAC-3", "10.1.1.4", "3");
    Switch *MySwitch4 = new Switch("MAC-4", "10.1.1.5", "4");
    send(MacTable, MySwitch1, MySwitch2);

    for (const auto &entry : MacTable.addressTable)
    {
        cout << "Port: " << entry.first << "\n";
        cout << "  MAC Address: " << entry.second.l2MacAddress << "\n";
        cout << "  IP Address:  " << entry.second.l3IpAddress << "\n";
        cout << "  Switch Port: " << entry.second.fAPortNo << "\n\n";
    }

    delete MySwitch1;
    delete MySwitch2;
    delete MySwitch3;
    delete MySwitch4;

    return 0;
}
