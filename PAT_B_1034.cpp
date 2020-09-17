#include <iostream>
#include <string>
using namespace std;
long long mcf(long long ac, long long bd) {
	if (ac < bd)swap(ac, bd);
	return !bd ? ac : mcf(bd, ac % bd);
}
string output(long long a, long long b) {
	if (b < 0) { b *= -1; a *= -1; }
	if (a == 0)return "0";
	else if (a > 0 && a < b)return to_string(a) + "/" + to_string(b);
	else if (a > 0 && a == b)return "1";
	else if (a > 0 && a > b) {
		long long mcfv = mcf(a - a / b * b, b);
		return to_string(a / b) + (a / b * b == a ? ")" : (" " + to_string((a - a / b * b) / mcfv) + "/" + to_string(b / mcfv)));
	}
	else if (a < 0 && abs(a) < b)return "(" + to_string(a) + "/" + to_string(b) + ")";
	else if (a < 0 && abs(a) == b)return "(-1)";
	else if (a < 0 && abs(a) > b) {
		long long mcfv = mcf(abs(a) - abs(a) / b * b, b);
		return "(" + to_string(a / b) + (a / b * b == a ? ")" : (" " + to_string((abs(a) - abs(a) / b * b) / mcfv) + "/" + to_string(b / mcfv)) + ")");
	}
	else return "-";
}
int main() {
	long long a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	long long bdmcf = mcf(b, d), maxmul = b * d / bdmcf, abmcfv = mcf(abs(a), b), cdmcfv = mcf(abs(c), d);
	long long bmul = maxmul / b, a1 = a * bmul, b1 = maxmul;
	long long dmul = maxmul / d, c1 = c * dmul, d1 = maxmul;
	long long a1Plusc1mcfv = mcf(abs(a1 + c1), maxmul), a1Minusc1mcfv = mcf(abs(a1 - c1), maxmul),
		a1Timesc1mcfv = mcf(abs(a * c), b * d), a1Dividec1mcfv = mcf(abs(a1), abs(c1));
	printf("%s + %s = %s\n", output(a / abmcfv, b / abmcfv).c_str(), output(c / cdmcfv, d / cdmcfv).c_str(), output((a1 + c1) / a1Plusc1mcfv, maxmul / a1Plusc1mcfv).c_str());
	printf("%s - %s = %s\n", output(a / abmcfv, b / abmcfv).c_str(), output(c / cdmcfv, d / cdmcfv).c_str(), output((a1 - c1) / a1Minusc1mcfv, maxmul / a1Minusc1mcfv).c_str());
	printf("%s * %s = %s\n", output(a / abmcfv, b / abmcfv).c_str(), output(c / cdmcfv, d / cdmcfv).c_str(), output(a * c / a1Timesc1mcfv, b * d / a1Timesc1mcfv).c_str());
	printf("%s / %s = %s", output(a / abmcfv, b / abmcfv).c_str(), output(c / cdmcfv, d / cdmcfv).c_str(), c1 == 0 ? "Inf" : output(a1 / a1Dividec1mcfv, c1 / a1Dividec1mcfv).c_str());
	return 0;
}
