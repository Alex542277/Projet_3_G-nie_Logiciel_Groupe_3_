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

std::vector<QString> IPCalculator::calculateSubnets() {
    std::vector<QString> result;
    int hostBits = 32 - subnetMask;
    int numSubnets = 1 << hostBits;

    for (int i = 0; i < numSubnets && i < 10; ++i) {
        std::bitset<32> subnet = ipBinary;
        subnet |= std::bitset<32>(i);
        QString ip;
        for (int j = 3; j>= 0; --j) {
            ip += QString::number((subnet.to_ulong()>> (j * 8)) & 0xFF);
            if (j!= 0) ip += ".";
}
        result.push_back(ip);
}
    return result;
}


