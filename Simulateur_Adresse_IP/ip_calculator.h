#ifndef IPCALCULATOR_H
#define IPCALCULATOR_H

#include <bitset>
#include <vector>
#include <QString>

class IPCalculator {
public:
    IPCalculator(const QString& ip, int mask);
    std::vector<QString> calculateSubnets();

private:
    std::bitset<32> ipBinary;
    int subnetMask;
    void parseIp(const QString& ip);
};

#endif

