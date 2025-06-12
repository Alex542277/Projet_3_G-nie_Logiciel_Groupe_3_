#include "ipcalculator.h"
#include <QStringList>

IPCalculator::IPCalculator(const QString& ip, int mask): subnetMask(mask) {
    parseIp(ip);
}

void IPCalculator::parseIp(const QString& ip) {
    QStringList octets = ip.split(".");
    int bitIndex = 24;
    for (const QString& octet: octets) {
        int val = octet.toInt();
        std::bitset<8> bits(val);
        for (int i = 0; i < 8; ++i)
            ipBinary[bitIndex++] = bits[i];
        bitIndex -= 16;
}
}

