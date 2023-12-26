#include "SwitchLibrary.h"

void MacTableValue::setValues(const string &mac, const string &ip, const string &port)
{
    l2MacAddress = mac;
    l3IpAddress = ip;
    fAPortNo = port;
}

Switch::Switch(string aInMacAddress, string aInIpAddress, string aInPortNo)
{
    lPort = new Port();
    lPort->l2MacAddress = aInMacAddress;
    lPort->l3IpAddress = aInIpAddress;
    lPort->fAPortNo = aInPortNo;
}

Switch::~Switch()
{
    delete lPort;
}

Port *Switch::getPort()
{
    return lPort;
}

void send(MacAddressTable &aInMac, Switch *aInFrom, Switch *aInTo)
{
    aInMac.addressTable.emplace(aInFrom->getPort()->fAPortNo, MacTableValue());
    aInMac.addressTable[aInFrom->getPort()->fAPortNo].setValues(
        aInFrom->getPort()->l2MacAddress,
        aInFrom->getPort()->l3IpAddress,
        aInFrom->getPort()->fAPortNo);

    aInMac.addressTable.emplace(aInTo->getPort()->fAPortNo, MacTableValue());
    aInMac.addressTable[aInTo->getPort()->fAPortNo].setValues(
        aInTo->getPort()->l2MacAddress,
        aInTo->getPort()->l3IpAddress,
        aInTo->getPort()->fAPortNo);
}